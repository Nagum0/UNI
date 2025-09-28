# PROTO 1

## Commands

### Init

- Initializes a new repository and creates the following:
  - obj/
  - heads/
  - INDEX.yaml and bootstraps it
  - HEAD.yaml and sets the ref to heads/main
  - Automatically creates the main branch in heads/

``` bash
proto init
```

## Head

- Points to the current branch head file

``` yaml
branch: <current active branch>
ref: heads/<branch name>
```

## Index

- Stores the files that are tracked and should be in the next commit

``` yaml
files:
  - path: <file path>
    hash: <file hash>
```

## Objects

### BLOB

- Just a compressed file placed in .prot/obj/hash

### DIRECTORY SNAPSHOT

- A snapshot of the directory structure of the staged files at the time of a commit.
- This replaces git's tree objects for a simpler one file solution with the tradeoff of efficiency (good for a prototype)

``` yaml
dirs:
  dirName:
    children: {}
    blobs: {}
blobs: {}
  ```

### COMMIT

``` yaml
snapshot: <tree hash>
parents:
  - hash: <parent hash>
metadata:
  committer: <committer name>
  email: <committer email>
  message: <commit message>
```

### TAG

``` yaml
type: <git object being tagged>
name: <tagname>
metadata:
  tagger:
    name: <tagger name>
    email: <tagger email>
  message: <tag message>
```
