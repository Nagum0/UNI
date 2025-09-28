package pkg

import (
	"bytes"

	"gopkg.in/yaml.v3"
)

type Index struct {
	Files map[string]string `yaml:"files"`
}

type Snapshot struct {
	Dirs     map[string]*Snapshot  `yaml:"dirs"`
	Blobs    map[string]string `yaml:"blobs"`
}

func NewSnapshot() *Snapshot {
	return &Snapshot{
		Dirs: make(map[string]*Snapshot),
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
