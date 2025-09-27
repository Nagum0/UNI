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
	indexFileData, _ := os.ReadFile(".prot/INDEX.yaml")
	var index Index
	yaml.Unmarshal(indexFileData, &index)

	root := createTree(index)
	fmt.Println(root.String())
}

func createTree(index Index) *Tree {
	root := NewTree()

	for filePath, hash := range index.Files {
		dirs := strings.Split(filePath, "/")

		if len(dirs) > 1 {
			currDir := root

			for _, dir := range dirs[:len(dirs) - 1] {
				if _, ok := currDir.Children[dir]; !ok {
					currDir.Children[dir] = NewTree()
				}

				currDir = currDir.Children[dir]
			}

			currDir.Blobs[dirs[len(dirs)-1]] = hash
		}
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
