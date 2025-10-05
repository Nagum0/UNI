package pkg

import (
	"bytes"
	"compress/zlib"
	"container/list"
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
	commit, _ := GetBranchTopCommit(branchName)
	
	// Read commit's snapshot
	snapshotFile, _ := os.ReadFile(".prot/obj/" + commit.Snapshot)
	var snapshot Snapshot
	yaml.Unmarshal(snapshotFile, &snapshot)

	// Update working directory and INDEX
	index := Index{ Files: make(map[string]string) }
	snapshot.UpdateWorkingDirectory(".", &index, true)

	// Updating INDEX.yaml file
	newIndexContents, _ := yaml.Marshal(index)
	newIndexFile, _ := os.Create(".prot/INDEX.yaml")
	defer newIndexFile.Close()
	newIndexFile.Write(newIndexContents)
}

// NOTE: Maybe use the INDEX???
// BUG: Deleted files not tracked
func Merge(otherBranch string) {
	head := GetHead()

	// Find common ancestor
	commonAncestor := findCommonAncestor(head.Branch, otherBranch)

	// Get indexes
	aCommit, _ := GetBranchTopCommit(head.Branch)
	bCommit, _ := GetBranchTopCommit(otherBranch)
	
	aIndex := aCommit.CreateIndex()
	bIndex := bCommit.CreateIndex()
	baseIndex := commonAncestor.CreateIndex()

	// Union of all tracked files among indexes
	union := indexUnion(aIndex, bIndex, baseIndex)

	// DEBUG
	for filePath, hashes := range union {
		fmt.Printf("%v: { A: %v B: %v Base: %v }\n", filePath, hashes.A, hashes.B, hashes.Base)
	}
}

type hashes struct {
	A    string
	B    string
	Base string
}

func indexUnion(a Index, b Index, c Index) map[string]hashes {
	union := make(map[string]hashes)

	for filePath, hash := range a.Files {
		union[filePath] = hashes{ A: hash }
	}

	for filePath, hash := range b.Files {
		if hashinfo, ok := union[filePath]; !ok {
			union[filePath] = hashes{ B: hash }
		} else {
			hashinfo.B = hash
			union[filePath] = hashinfo
		}
	}
	
	for filePath, hash := range c.Files {
		if hashinfo, ok := union[filePath]; !ok {
			union[filePath] = hashes{ Base: hash }
		} else {
			hashinfo.Base = hash
			union[filePath] = hashinfo
		}
	}

	return union
}

func findCommonAncestor(a string, b string) *CommitObject {
	_, aHash := GetBranchTopCommit(a)
	_, bHash := GetBranchTopCommit(b)
	
	visited := make(map[string]CommitObject)
	queue := list.List{}
	queue.Init()

	// Visit A commits
	queue.PushBack(aHash)
	for queue.Len() != 0 {
		listElem := queue.Back()
		queue.Remove(listElem)

		commitHash := listElem.Value.(string)
		commit := UnmarshalCommit(ReadObject(commitHash))
		visited[commitHash] = commit

		for _, parent := range commit.Parents {
			queue.PushBack(parent)
		}
	}

	// Check for ancestor with B
	queue.PushBack(bHash)
	for queue.Len() != 0 {
		listElem := queue.Back()
		queue.Remove(listElem)

		commitHash := listElem.Value.(string)
		commit := UnmarshalCommit(ReadObject(commitHash))

		if c, ok := visited[commitHash]; ok {
			return &c
		}

		for _, parent := range commit.Parents {
			queue.PushBack(parent)
		}
	}

	return nil
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
