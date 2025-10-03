package pkg

import (
	"bytes"
	"compress/zlib"
	"fmt"
	"io"
	"os"
	"strings"

	"gopkg.in/yaml.v3"
)

type Head struct {
	Branch string `yaml:"branch"`
	Ref    string `yaml:"ref"`
}

func GetHead() Head {
	headFile, _ := os.ReadFile(".prot/HEAD.yaml")
	var head Head
	yaml.Unmarshal(headFile, &head)
	return head
}

func UpdateBranchHead(commitHash string) {
	head := GetHead()
	branchHead, _ := os.Create(".prot/heads/" + head.Branch)
	defer branchHead.Close()
	branchHead.WriteString(commitHash)
}

// Switch the current branch and ref to branchName in HEAD.yaml
func SwitchBranch(branchName string) {
	head := GetHead()
	head.Branch = branchName
	head.Ref = fmt.Sprintf("heads/%v", branchName)

	newHeadContents, _ := yaml.Marshal(head)
	headFile, _ := os.Create(".prot/HEAD.yaml")
	defer headFile.Close()
	headFile.Write(newHeadContents)
}

type Index struct {
	Files map[string]string `yaml:"files"`
}

type Snapshot struct {
	Dirs  map[string]*Snapshot `yaml:"dirs"`
	Blobs map[string]string    `yaml:"blobs"`
}

func NewSnapshot() *Snapshot {
	return &Snapshot{
		Dirs:  make(map[string]*Snapshot),
		Blobs: make(map[string]string),
	}
}

// Update working directory to look like the Snapshot's directory structure and
// update the INDEX to match the commit's tracked files
func (s Snapshot) UpdateWorkingDirectory(dirs string, index *Index) {
	for fileName, hash := range s.Blobs {
		filePath := fmt.Sprintf("%v/%v", dirs, fileName)
		filePath = strings.TrimPrefix(filePath, "./")
		contents, _ := zlibDecompress(hash)
		file, _ := os.Create(filePath)
		defer file.Close()
		file.Write(contents)
		index.Files[filePath] = hash
	}

	for dirName, dirSnapshot := range s.Dirs {
		dirSnapshot.UpdateWorkingDirectory(dirs + "/" + dirName, index)
	}
}

// Decompress the byte slice from zlib.
func zlibDecompress(hash string) ([]byte, error) {
	contents, err := os.ReadFile(".prot/obj/" + hash)
	if err != nil {
		return nil, err
	}

    contentsReader := bytes.NewReader(contents)
    reader, err := zlib.NewReader(contentsReader)
    if err != nil {
        return nil, err
    }
    defer reader.Close()
    
    decompressedBytes := bytes.Buffer{}
    if _, err := io.Copy(&decompressedBytes, reader); err != nil {
        return nil, err
    }

    return decompressedBytes.Bytes(), nil
}

func (t Snapshot) String() string {
	var buf bytes.Buffer
	enc := yaml.NewEncoder(&buf)
	defer enc.Close()
	enc.SetIndent(2)
	enc.Encode(t)
	return buf.String()
}

type CommitMetadata struct {
	Committer string `yaml:"committer"`
	Email     string `yaml:"email"`
	Message   string `yaml:"message"`
}

type CommitObject struct {
	Snapshot string         `yaml:"snapshot"`
	Parents  []string       `yaml:"parents"`
	Metadata CommitMetadata `yaml:"metadata"`
}

func UnmarshalCommit(contents []byte) CommitObject {
	var commit CommitObject
	yaml.Unmarshal(contents, &commit)
	return commit
}

func GetBranchTopCommit(branch string) (CommitObject, string) {
	branchHeadFile, _ := os.ReadFile(".prot/heads/" + branch)
	commitFile, _ := os.ReadFile(".prot/obj/" + string(branchHeadFile))
	return UnmarshalCommit(commitFile), string(branchHeadFile)
}

func (c CommitObject) String() string {
	var buf bytes.Buffer
	enc := yaml.NewEncoder(&buf)
	defer enc.Close()
	enc.SetIndent(2)
	enc.Encode(c)
	return buf.String()
}

// Returns the current HEAD branch freshest commit.
// If the branch is new it returns an empty string and false.
func GetTopCommitHash() (string, bool) {
	head := GetHead()

	branchHead, _ := os.ReadFile(".prot/" + head.Ref)
	if len(branchHead) == 0 {
		return "", false
	}

	return string(branchHead), true
}

func WriteObject(hash string, contents []byte) {
	file, _ := os.Create(".prot/obj/" + hash)
	defer file.Close()
	file.Write(contents)
}

func ReadObject(hash string) []byte {
	out, _ := os.ReadFile(".prot/obj/" + hash)
	return out
}
