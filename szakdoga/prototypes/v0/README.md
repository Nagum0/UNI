# PROTO 1

## Head

- Points to the current branch head file

``` yaml
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

### TREE

``` yaml
object: Tree
hash: <tree hash>
parent: <parent hash>
children:
  - hash: <child hash>
    # blob or tree
    type: <child type>
    # file name or folder name
    name: <child name>
```

``` yaml
hash: <tree hash>
children:
  - dir: <subdirectory name>
    children: ...
    blobs: ...
blobs:
  - name: <file name>
    hash: <blob hash>
```

### COMMIT

``` yaml
object: Commit
hash: <commit's hash>
tree: <tree hash>
parents:
  - hash: <parent hash>
metadata:
  committer:
    name: <committer's name>
    email: <committer's email>
  message: <commit message>
```

### TAG

``` yaml
object: Tag
type: <git object being tagged>
name: <tagname>
metadata:
  tagger:
    name: <tagger's name>
    email: <tagger's email>
  message: <tag message>
```
