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

### Add 

- Adds a file to the INDEX and compresses it and stores the blob in the
  object database

``` bash
proto add <file path>
```

### Commit

- Takes a snapshot of the tracked directory structure and creates a commit object
- Details:
  1. Create a Snapshot from the INDEX and write it to the object database
  2. Create the Commit object
  3. Collect parent commits (there are multiple in case of a merge commit) and update the Commit object
  4. Write the Commit object to the object database
  5. Update the heads/current branch to the new commit objects hash

``` bash
proto commit <message>
```

### Branch

- Create a new branch
- Details:
  1. Creates a new file in the heads/ folder for the new branch
  2. Set the new branch to point to the current commit object

``` bash
proto branch <branch name>
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
