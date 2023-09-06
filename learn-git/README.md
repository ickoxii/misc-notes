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

    ```bash
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
    ```

We will now go through this code line by line and dissect it.

> `cd path/to/project`

move to directory

> `git init`

Initialize the git repository. In our example, we assumed that we have an
existing local repository that already has files. If we are starting fresh
without a local repository, then after creating the repository on GitHub, we can
use `git clone` instead of `git init`. By using `git clone`, we no longer have
to use `git init` and `git remote add origin <link>`

    ```bash
    git clone https://github.com/username/repository-name.git
    ```

> `echo "# Title of Project" >> README.md`

GitHub uses a Markdown file named *README.md* to print information about the
repository on the repositories main page. This README file is written by the
developer and should provide adequate information on the repository.

> `git add .`

Add the entire directory to the staging area.

> `git commit -m "Initial commit"`

`git commit` captures a snapshot of the changes in your local directory (changes
added to the staging area from `git add` or `git commit -a`), effectively
creating a new version in your local Git history.

> `git remote add origin https://github.com/username/repository-name.git`

This is completely optional, and is only needed if we are wanting to create a
remote repository on GitHub. We will still have a local Git
repository on our device without invoking this line.

> `git push -u origin main`

`git push` sends our local commits to a remote repository. `git push` is not
needed if you're only using a local repository with no intention of sharing or
backing up changes to a remote repository.

> `git checkout -b new_branch_name`

`git checkout` is used to create a new branch within our Git repository. In Git
versions 2.23 and later, `git switch` can be used in replacement for `git
checkout` (although some flags may be different. i.e., `git checkout -b` is
equivalent to `git switch -c`).

> `vim file-to-change`

Opens the file to change in vim so you can make edits.

> `git status`

Provides information about the current state of your working directory relative
to the current branch. `git status` prints the following details:

- **Current Branch**
- **Changes that are staged (ready to be committed)**
- **Changes not staged for commit**
- **Untracked files**
- **Divergence Information**

> `git add -p file-to-change`

Adding the `-p` flag to `git add` puts us in "patch" mode. This allows us to
interactively select chunks from changes made to the file to get ready for
commit.

> `git commit`

Running `git commit` without the `-m` option opens up a file in your default
text editor that allows you to make more descriptive commit messages. Saving and
quitting the editor will commit the changes with the text you added.

> `git branch`

This displays all Git branches in the current repository.

> `git checkout main`

After making our changes, we move back to the branch we want to merge our
changes into. Note we do not have to use a flag since we are moving to a branch
that already exists.

> `git pull origin main`

This is optional but recommended if collaborating with others. It is good
practice to pull the latest changes from the remote repository to ensure you're
merging with the most recent code.

> `git merge new_branch_name`

Merge our branch back into main. If there are any merge conflicts, you'll need
to resolve them manually. Once resolved, you would then commit the resolved
changes.

> `git push origin main`

After the merge is successfull and you've resolved any potential conflicts, push
the changes to the remote repository.

> `git branch -d new_branch_name`
> `git push origin --delete new_branch_name`

(Optional) Delete the branch locally and remotely.

> `git log`

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

> `git clone https://github.com/username/repository-name.git`

### No Remote Repository

If we are not using a remote repository, then the following commands are not
needed:

1. `git remote add origin <link>`: this sets up a remote origin.
2. `git push`, `git pull`: these commands are only used in the context of
pushing or pulling from a remote repository.

### `git checkout` Flags

1. `-b`: Create a new branch and switch to it

> `git checkout -b new_branch_name`

2. `-B`: Create a new branch or reset an existing branch to a specified starting
point.

> `git checkout -B existing_or_new_branch_name`

3. `-t`, `--track`: When creating a new branch, set up to "upstream"
configuration. This is usually used with remote branches.

> `git checkout --track origin/remote_branch_name`

4. `-l`: Create a new branch but keep its logs in refs/heads/.

5. `-f`, `--force`: Force checkout, even if there are conflicts.

6. `-q`, `--quiet`: Operate quietly. Suppresses feedback messages.

7. `--orphan`: Create a new orphan branch. The first commit made on this new
branch will have no parents, and it will be the root of a new history completely
disconnected from all the other branches and commits.

> `git checkout --orphan new_orphan_branch_name`

8. `-p`, `--patch`: Interactively selects chunks in the difference between the
current branch and the given commit (or the index, if no commit is given). This
is used to selectively discard changes from the working tree.


