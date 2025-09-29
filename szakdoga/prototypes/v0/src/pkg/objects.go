package pkg

import (
	"bytes"
	"os"

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
