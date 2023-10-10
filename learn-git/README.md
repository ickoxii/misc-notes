# Using Git, Learning About Branches, Commiting Changes

Git is a distributed **version control system** (VCS) designed to track changes
in source code during software development. It allows multiple developers to
work on a project simultaneously, ensuring that their individual contributions
are tracked, merged, and integrated seamlessly. Git was created by Linus
Torvalds in 2005 for the development of the Linus kernel.

## Key Features and Concepts Associated With Git

1. **Distributed Version Control**: Unlike centralized version control systems, 
    every Git directory on every computer is a full-fledged repository with a
    complete history and full version-tracking capabilities, independent of 
    network access or a central server.

2. **Commits**: A commit is like a snapshot of your work at a particular point
    in time. Each commit has a unique ID (often referred to as a commit hash),
    allowing you to track changes, revert to previous states, or compare
    different versions of files.

3. **Branching**: Git allows developers to create branches in their
    repositories, which are essentially separate lines of development. This is
    especially useful when working on new features or experiments without
    affecting the main (often called the `main` or `master`).

4. **Merging**: Once the work on a branch is complete, Git provides tools to
    merge those changes back into the `main` branch (or any other branch).

5. **Remote Repositories**: While Git can function entirely locally, it also
    supports remote repositories, allowing teams to collaborate online.
    Platforms like GitHub, GitLab, and Bitbucket provide hosting for Git
    repositories and offer features that facilitate collaborative work, like
    pull requests and code reviews.

6. **Cloning**: You can create a local copy of a remote repository on your
    machine by "cloning" it. This local copy includes all the repository's
    history, branches, and commits.

7. **Pulling and Pushing**: Changes from a remote repository can be fetched and
    integrated into your local repository by using the `pull` command.
    Conversely, changes in your local repository can be sent to the remote
    repository using the `push` command.

8. **Staging Area**: Before committing changes they are first added to what's
    called the staging area. This allows you to group related changes into a
    single commit.

9. **Conflict Resolution**: If multiple developers (or a single, disorganized
    one) modify the same part of a codebase (from different branches) and try to
    merge their changes, Git will highlight the conflict, allowing developers to
    manually resolve it.

10. **History and Log**: One of the main advantages of Git is its ability to
    keep track of the entire history of the project. You can easily view and
    navigate this history using the log command.

11. **Distributed but Centralized Workflow**: While each developer gets their
    full copy of the project, there's usually a single canonical repository that
    hosts the "official" version of the project.

## Initializing a Git Repository, Making Changes and Merging Branches

The following code assumes we are starting from an existing local repository
that already has files within.

    cd path/to/project
    git init
    echo "# Title of Project" >> README.md
    git add .
    git commit -m "Initial commit"
    git remote add origin https://github.com/username/repository-name.git
    git push -u origin main
    git checkout -b new_branch_name
    vim file-to-change
    git status
    git add -p file-to-change
    git commit
    git branch
    git checkout main
    git pull origin main
    git merge new_branch_name
    git push -u origin main
    git branch -d new_branch_name
    git log

We will now go through this code line by line and dissect it.

    1. cd path/to/project

move to directory

    2. git init

Initialize the git repository. In our example, we assumed that we have an
existing local repository that already has files. If we are starting fresh
without a local repository, then after creating the repository on GitHub, we can
use `git clone` instead of `git init`. By using `git clone`, we no longer have
to use `git init` and `git remote add origin <link>`

    git clone https://github.com/username/repository-name.git

    3. echo "# Title of Project" >> README.md

GitHub uses a Markdown file named *README.md* to print information about the
repository on the repositories main page. This README file is written by the
developer and should provide adequate information on the repository.

    4. git add .

Add the entire directory to the staging area.

    5. git commit -m "Initial commit"

`git commit` captures a snapshot of the changes in your local directory (changes
added to the staging area from `git add` or `git commit -a`), effectively
creating a new version in your local Git history.

    6. git remote add origin https://github.com/username/repository-name.git

This is completely optional, and is only needed if we are wanting to create a
remote repository on GitHub. We will still have a local Git
repository on our device without invoking this line.

    7. git push -u origin main

`git push` sends our local commits to a remote repository. `git push` is not
needed if you're only using a local repository with no intention of sharing or
backing up changes to a remote repository.

    8. git checkout -b new_branch_name

`git checkout` is used to create a new branch within our Git repository. In Git
versions 2.23 and later, `git switch` can be used in replacement for `git
checkout` (although some flags may be different. i.e., `git checkout -b` is
equivalent to `git switch -c`).

    9. vim file-to-change

Opens the file to change in vim so you can make edits.

    10. git status

Provides information about the current state of your working directory relative
to the current branch. `git status` prints the following details:

- **Current Branch**
- **Changes that are staged (ready to be committed)**
- **Changes not staged for commit**
- **Untracked files**
- **Divergence Information**

    11. git add -p file-to-change

Adding the `-p` flag to `git add` puts us in "patch" mode. This allows us to
interactively select chunks from changes made to the file to get ready for
commit.

    12. git commit

Running `git commit` without the `-m` option opens up a file in your default
text editor that allows you to make more descriptive commit messages. Saving and
quitting the editor will commit the changes with the text you added.

    13. git branch

This displays all Git branches in the current repository.

    14. git checkout main

After making our changes, we move back to the branch we want to merge our
changes into. Note we do not have to use a flag since we are moving to a branch
that already exists.

    15. git pull origin main

This is optional but recommended if collaborating with others. It is good
practice to pull the latest changes from the remote repository to ensure you're
merging with the most recent code.

    16. git merge new_branch_name

Merge our branch back into main. If there are any merge conflicts, you'll need
to resolve them manually. Once resolved, you would then commit the resolved
changes.

    17. git push origin main

After the merge is successfull and you've resolved any potential conflicts, push
the changes to the remote repository.

    18. git branch -d new_branch_name
     git push origin --delete new_branch_name

(Optional) Delete the branch locally and remotely.

    19. git log

View the commit history of a Git repository. It displays a list of commits, from
the most recent to the oldest, providing information about each commit such as
the commit author, the timestamp of the commit, and the commit message.

## Variables

In our code, we assumed that we worked with an initially non-empty local
directory. We also assumed we are utilizing a remote repository as well as a
local repository. 

### Starting With an Initially Empty Directory

If we do not have any files to start with, we can skip the `git init` and `git
add .` Instead, we can use:

    git clone https://github.com/username/repository-name.git

### No Remote Repository

If we are not using a remote repository, then the following commands are not
needed:

1. `git remote add origin <link>`: this sets up a remote origin.
2. `git push`, `git pull`: these commands are only used in the context of
pushing or pulling from a remote repository.

### `git checkout` Flags

1. `-b`: Create a new branch and switch to it

    git checkout -b new_branch_name

2. `-B`: Create a new branch or reset an existing branch to a specified starting
point.

    git checkout -B existing_or_new_branch_name

3. `-t`, `--track`: When creating a new branch, set up to "upstream"
configuration. This is usually used with remote branches.

    git checkout --track origin/remote_branch_name

4. `-l`: Create a new branch but keep its logs in refs/heads/.

5. `-f`, `--force`: Force checkout, even if there are conflicts.

6. `-q`, `--quiet`: Operate quietly. Suppresses feedback messages.

7. `--orphan`: Create a new orphan branch. The first commit made on this new
branch will have no parents, and it will be the root of a new history completely
disconnected from all the other branches and commits.

    git checkout --orphan new_orphan_branch_name

8. `-p`, `--patch`: Interactively selects chunks in the difference between the
current branch and the given commit (or the index, if no commit is given). This
is used to selectively discard changes from the working tree.

## Making Mistakes

Everyone makes mistakes. Luckily, Git is a distributed version control system.
That means it has operations that allow you to revert changes and go to previous
commited versions of your files.

### Cancelling Commits

If you have already staged files (using `git add`), you can remove these files
from the staging area before you use `git commit` by using:

    git restore --staged <files>

### Checkout a Previous Commit (detach HEAD)

To temporarily go back, or "checkout", a previous commit:

    git checkout <commit_hash>

This will detach the HEAD, meaning you're no longer on any branch but have check
out the code from a specific commit. This is good for temporary explorations. If
you want to make changes and start a new branch from this point, you can create
a new branch while in this state:
   
    git checkout -b new_branch_name

### Revert a Specific Commit

If you want to undo the changes introduced by a specific commit and create a new
commit that undoes those changes, use:

    git revert <commit_hash>

This command will create a new commit that undoes the changes from the specified
commit. It's a safe way to undo changes without rewriting history.

### Reset

If you want to discard commits, you can use `git reset`. However, be careful
with this command, especially if you've already pushed commits to a remote
repository.

#### Soft Reset
    
    git reset --soft <commit_hash>

This command will move the HEAD and the current branch pointer to the specified
commit but will leave your staged changes and working directory intact.

#### Mixed Reset (default)

    git reset --mixed <commit_hash>
    \# OR
    git reset <commit_hash>

This moves the HEAD and current branch pointer to the specified commit, unstages
changes, but leaves the working directory intact.

#### Hard Reset

    git reset --hard <commit_hash>

This discards all changes since the specified commit, both in the staging area
and working directory. Use this with caution!

## Finding Your Commit Hash With `git reflog`

`git reflog`, or reference log, can be used to see a log of where the
`HEAD` and branch references have been. Every entry in the `reflog` shows a
state of your repository, and you can use the associated commit hash to return
to that state.

Here is a basic overview of how it works:

1. **View the reflog**:

    git reflog

This will produce an output like:
    
    a1b2c3d HEAD@{0}: commit: Add new feature
    e4f5g6h HEAD@{1}: reset: moving to HEAD~2
    j7k8l0m HEAD@{2}: commit: Make some changes
    ...

Each entry has a reference like `HEAD@{n}` and an associate commit hash.

2. **Go back to a previous state**:

If you decide you want to go back to a previous state, you can use `git reset`
with the hash:

    git reset --hard a1b2c3d

Or with the reflog reference:
    
    git reset --hard HEAD@{1}

While the commit history (i.e., `git log`) only shows commits and the paths
taken, `git reflog` keeps track of the places your `HEAD` and branches have
been, making it a powerful tool for recovering from mistakes or just revisiting
changes.

`HEAD` is a special kind of reference, pointing to the current commit (or
sometimes, as in the case of a detached HEAD, directly to a commit without
involving a branch reference).
    
### Using `git diff` in `git reflog` to See Differences in Past Commits and the
### Current Working Directory

1. **View the reflog**:

    git reflog

This will produce output, see above.

2. **Compare a reflog entry with the current working directory**:

If you want to see the difference between a specific reflog entry and your
current working directory, use a `git diff` with the associated ref:

    git diff HEAD@{1}

This command will show you the difference between the state of your project at
`HEAD@{1}` and your current working directory.

If you want to see the difference between the actual commits (rather than
between a commit and a working directory), you can use:

    git diff HEAD@{1} HEAD@{0}

This will show the difference between the states of your project at `HEAD@{1}`
and `HEAD@{0}`.

## MISC

### Using `git rm`

Sometimes a path between your git repository and your local working directory
will change. This might occur because you move a file, or change a directory
name, etc.

Sometimes you want to remove a file from your git repository but keep it on your
local directory. In these cases, use:

    git rm --cached <file_or_directory>

The `--cached` flag removes tracking from your Git repository while leaving the
file or directory on your local working directory.

#### Removing a bunch of cached files

    git status | grep 'deleted:' | awk '{print $2}' | xargs git rm --cached

`git status` : lists all changes including deleted files
`grep 'deleted:'` : filters output to show only lines with 'deleted:'
`awk '{print $2}'` : processes the filtered output to extract just the file
paths
`xargs git rm --cached` : passes the file paths to the `git rm --cached`
command, which will un-stage these files.
