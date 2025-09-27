package pkg

import (
	"bytes"

	"gopkg.in/yaml.v3"
)

type Index struct {
	Files map[string]string `yaml:"files"`
}

type Tree struct {
	Children map[string]*Tree  `yaml:"children"`
	Blobs    map[string]string `yaml:"blobs"`
}

func NewTree() *Tree {
	return &Tree{
		Children: make(map[string]*Tree),
		Blobs: make(map[string]string),
	}
}

func (t Tree) String() string {
	var buf bytes.Buffer
	enc := yaml.NewEncoder(&buf)
	defer enc.Close()
	enc.SetIndent(2)
	enc.Encode(t)
	return buf.String()
}
