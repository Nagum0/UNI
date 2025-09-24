# GIT CLONE

This project is a simplified implementation of Git, designed to demonstrate the core principles of version control systems. 
It replicates the essential features of Git such as repository initialization, staging, committing, branching, and merging, 
while also providing tools to inspect commit history and internal repository objects.

## FEATURES

### Init

- Initialize a repository

### Add

- Add the modified items to the staging area

### Commit

- Create a snapshot of the staging area and save it to history
- Implement the ability to jump between commits

### Branching

- Create and switch between branches
- A branch just holds it's own line of commits

### Merge branches

- Merge branches and show merge conflicts (if any) using diffs

### Logging & History

- Show the commit history of a branch
- Log specific information about objects such as
  - Stagiing index
  - Blob files
  - Commit objects
  - Tree objects

### Remote repositories

- A server to host repositories remotely and the ability to fetch and push to the remote repositories

### Fetch

- Fetches all the remote objects that the client doesn't have to its own remote branch (the user can merge with the remote
  branch to get the state of the remote repository)

### Push

- Send the new objects to the remote repository and check for any conflicts in the refs
