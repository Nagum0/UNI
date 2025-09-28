package pkg

import (
	"bytes"
	"compress/zlib"
	"crypto/sha1"
	"fmt"
	"os"
	"strings"

	"gopkg.in/yaml.v3"
)

func Init() {
	// Create needed directories
	os.Mkdir(".prot", os.ModePerm)
	dirs := []string{"obj", "heads"}
	for _, dir := range dirs {
		os.Mkdir(fmt.Sprintf(".prot/%v", dir), os.ModePerm)
	}
	
	// Create and bootstrap INDEX
	index := Index{}
	out, _ := yaml.Marshal(index)
	indexFile, _ := os.Create(".prot/INDEX.yaml")
	defer indexFile.Close()
	indexFile.Write(out)

	// Create main branch
	main, _ := os.Create(".prot/heads/main")
	defer main.Close()

	// Create and bootstrap HEAD
	headObject := Head{
		Branch: "main",
		Ref: "heads/main",
	}
	head, _ := yaml.Marshal(headObject)
	headFile, _ := os.Create(".prot/HEAD.yaml")
	defer headFile.Close()
	headFile.Write(head)
}

func Add(filePath string) {
	contents, _ := os.ReadFile(filePath)

	// Loading INDEX
	indexFileData, _ := os.ReadFile(".prot/INDEX.yaml")
	var index Index
	yaml.Unmarshal(indexFileData, &index)
	
	// Generating SHA1 hash
	hash := genSHA1(contents)
	currentHash, ok := index.Files[filePath]

	// Return if file didn't change
	if ok && hash == currentHash {
		return
	} else {
		index.Files[filePath] = hash
	}

	// Compress file
	compressedContents := zlibCompress(contents)
	blobFile, _ := os.Create(".prot/obj/" + hash)
	defer blobFile.Close()
	blobFile.Write(compressedContents)

	// Updating INDEX
	indexFile, _ := os.Create(".prot/INDEX.yaml")
	defer indexFile.Close()
	out, _ := yaml.Marshal(index)
	indexFile.Write(out)
}

func Commit(msg string) {
	// Reading INDEX
	indexFileData, _ := os.ReadFile(".prot/INDEX.yaml")
	var index Index
	yaml.Unmarshal(indexFileData, &index)
	
	// Creating snapshot object
	snapshotObject := createSnapshot(index)
	snapshotHash := genSHA1([]byte(snapshotObject.String()))
	WriteObject(snapshotHash, []byte(snapshotObject.String()))

	// Creating commit object
	commitObject := CommitObject{
		Snapshot: snapshotHash,
		Metadata: CommitMetadata{
			Committer: "<test>",
			Email: "<test>",
			Message: msg,
		},
	}

	parent, ok := GetTopCommitHash()
	if ok {
		commitObject.Parents = append(commitObject.Parents, parent)
	}

	commitHash := genSHA1([]byte(commitObject.String()))
	WriteObject(commitHash, []byte(commitObject.String()))

	// Update heads/<current branch>
	UpdateBranchHead(commitHash)
}

func createSnapshot(index Index) *Snapshot {
	root := NewSnapshot()

	for filePath, hash := range index.Files {
		dirs := strings.Split(filePath, "/")
		currDir := root

		if len(dirs) > 1 {
			for _, dir := range dirs[:len(dirs) - 1] {
				if _, ok := currDir.Dirs[dir]; !ok {
					currDir.Dirs[dir] = NewSnapshot()
				}

				currDir = currDir.Dirs[dir]
			}
		}

		currDir.Blobs[dirs[len(dirs)-1]] = hash
	}

	return root
}

func zlibCompress(contents []byte) []byte {
    buffer := bytes.Buffer{}
    zlibWriter := zlib.NewWriter(&buffer)
    zlibWriter.Write(contents)
    zlibWriter.Close()
    return buffer.Bytes()
}

func genSHA1(contents []byte) string {
    return fmt.Sprintf("%x", sha1.Sum(contents))
}
