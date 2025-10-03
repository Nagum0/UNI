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

func Get(command string) {
	switch command {
	case "branch":
		branches := getBranches()
		head := GetHead()
		for _, branch := range branches {
			if branch == head.Branch {
				fmt.Printf(" * %v\n", branch)
			} else {
				fmt.Printf("   %v\n", branch)
			}
		}
	}
}

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
		Ref:    "heads/main",
	}
	head, _ := yaml.Marshal(headObject)
	headFile, _ := os.Create(".prot/HEAD.yaml")
	defer headFile.Close()
	headFile.Write(head)
}

func Add(filePath string) {
	filePath = strings.TrimPrefix(filePath, "./")
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
			Email:     "<test>",
			Message:   msg,
		},
	}

	parent, ok := GetTopCommitHash()
	if ok {
		commitObject.Parents = append(commitObject.Parents, parent)
	}

	commitHash := genSHA1([]byte(commitObject.String()))
	WriteObject(commitHash, []byte(commitObject.String()))

	// Update the head of the branch to new commit
	UpdateBranchHead(commitHash)
}

func Branch(branchName string) {
	// Cheack whether branch already exists
	branches := getBranches()
	for _, branch := range branches {
		if branch == branchName {
			panic(fmt.Sprintf("Branch %v already exists", branch))
		}
	}
	
	// Creating branch file
	branchFile, _ := os.Create(".prot/heads/" + branchName)
	defer branchFile.Close()

	// Setting up new branch
	if topCommitHash, ok := GetTopCommitHash(); ok {
		branchFile.WriteString(topCommitHash)
	}
}

func Checkout(branchName string) {
	// Update HEAD
	SwitchBranch(branchName)

	// Read top commit
	_, ok := GetTopCommitHash()
	if !ok {
		return
	}
	commit := GetBranchTopCommit(branchName)
	
	// Read commit's snapshot
	snapshotFile, _ := os.ReadFile(".prot/obj/" + commit.Snapshot)
	var snapshot Snapshot
	yaml.Unmarshal(snapshotFile, &snapshot)

	// Update working directory and INDEX
	index := Index{ Files: make(map[string]string) }
	snapshot.UpdateWorkingDirectory(".", &index)

	// Updating INDEX.yaml file
	newIndexContents, _ := yaml.Marshal(index)
	newIndexFile, _ := os.Create(".prot/INDEX.yaml")
	defer newIndexFile.Close()
	newIndexFile.Write(newIndexContents)
}

func Merge(otherBranch string) {
	head := GetHead()
	commonAncestor := findCommonAncestor(head.Branch, otherBranch)
	fmt.Println(commonAncestor)
}

func findCommonAncestor(b1 string, b2 string) string {
	// Read branch commit objects
	b1Commit := GetBranchTopCommit(b1)
	b2Commit := GetBranchTopCommit(b2)

	for (len(b1Commit.Parents) != 0 && len(b2Commit.Parents) != 0) && 
	    (b1Commit.Parents[0] != b2Commit.Parents[0]) {
		b1Commit = UnmarshalCommit(ReadObject(b1Commit.Parents[0]))
		b2Commit = UnmarshalCommit(ReadObject(b2Commit.Parents[0]))
	}

	return b1Commit.Parents[0]
}

func getBranches() []string {
	var branches []string
	headsDir, _ := os.ReadDir(".prot/heads")
	
	for _, entry := range headsDir {
		if !entry.IsDir() {
			branches = append(branches, entry.Name())
		}
	}

	return branches
}

func createSnapshot(index Index) *Snapshot {
	root := NewSnapshot()

	for filePath, hash := range index.Files {
		dirs := strings.Split(filePath, "/")
		currDir := root

		if len(dirs) > 1 {
			for _, dir := range dirs[:len(dirs)-1] {
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
