# Learning Git Basics

The following notes are taken from a few sources.

---

[Git for Professionals Tutorial](https://www.youtube.com/watch?v=Uszj_k0DGsg&t=1037s)

---

## Basic Commands

---

There are some basic commands you should know before you start using Git.

### Starting Up

The first time you use git, you should initialize your name and email

> `git config --global user.name "name"`
> `git config --global user.email "email"`

### `git status`

The `git status` command shows differences between the index file and
the current HEAD commit, paths that have differences between the
working tree and the index file, and paths in the working tree
that are not tracked by Git (and are not ignored by gitignore).
(The first are what you would **would** commit by running
`git commit`; the second and third are what you **could** commit by
running `git add` before running `git commit`.

For example, running the following when in a git repository:

> `git status`

### `git log`

The `git log` command provides information on the most recent commit.
It shows the author, date and time, and commit message.

> `git log`

---

## The Perfect Commit

---

1. Add the right changes.
2. Compose a good commit message!

- Don't cram every single change into the same commit
- You can even commit part of a file's overall changes in one commit,
    and bunch the rest of the file's overall changes in another commit.

### Adding the Right Changes

Idealy, you want each commit to be for its own individual topic.
A single commit should not be over cluttered so that past changes
may be referenced easily in the future.

#### Adding files

use the `git add` and/or `git commit -a` commands to add files.

for example:

> `git add file.txt file2.txt`

#### Git Diff

The `git diff` command allows you to view changes a file since
the last commit.

for example:

> `git diff file.txt`

#### -p Flag

The `-p` flag brings us down to the patch level, allowing us to
step through all changes in a file and adds designated portions
to the staging area during the staging process.

for example:

> `git add -p file.txt`

This allows us to separate changes to their own individual commits,
keeping commits organized to their own topic.

### Compose a Good Commit Message

A good commit message should have the following:

1. Subject = concise summary of what happened
2. Body = more detailed explanation
    - What is now different than before?
    - What is the reason for the change?
    - Is there anything to watch out for? anything particularly remarkable?

If a commit message is too wordy, it may be a sign you are trying
to commit too many things in the same commit.

#### git commit

Use `git commit` to add a commit message. Using `git commit` without 
any extra arguments will open an extra window where you may add your
commit message, with room for a large commit message.

for example:

> `git commit`

Add your changes in the window, then save and quit. Your message will
be commit. 

##### -m

You can append the -m flag to the `git commit` command in order
to add a quick commit message from the command line.

> `git commit -m "Commit message goes here"`

---

## Branching Strategies

---

Git allows you create branches however you so fit, which is a
blessing and a curse. Make sure you have a well-structure and
formulated approach to your branching method. If you are working
with a team, make sure everyone is aware of and adheres to an
agreed upon branching method.

### Integrating Changes & Structuring Releases

That being said, we will go over the two extreme models of
branching:

1. Mainline Development ("Always Be Integrating")
2. State, Release, and Feature Branches

### Mainline Development

Code is quickly integrated into your mainline/production code.

- few branches
    - very easy to keep track of things
- relatively small commits
    - cannot commit large changes to things that are constantly
    being commit to production code.
- high-quality testing and QA standards
    - as a result of constant deployment

This is probably the mode for me, since I am the only one using
my code, and I actually require constant deployment, so it would
not be an issue for me.

### State, Release, and Feature Branches

The premise of this model is that branches enhance structures and
workflow. Different types of branches fulfill different types
of jobs. For example, a main branch, develop branch, and feature
branch.

Will not go too much into this because I don't think its too
applicable for what I need.

---

## Pull Requests

---

Pull requests allow developers to communicate about and review
code. They invite other reviewers to provide feedback before 
merging.

Pull requests also allow you to contribute code to other
repositories that you do not have access to.

Pull requests are based on ***branches***, not individual commits.

### Forks

A **fork** is your personal copy of a git repository. For example,
you have an idea for extra implementation for an open source
project where you do not have direct push access to. You create
a 'Fork' of the original repository where you can make changes.
You can then submit a pull request to update the changes in the
original repository. An original owner of the repository can then
choose to approve your changes via the pull request.

> 1. Go to reposity on [github] "https://github.com"
> 2. Click the fork button
> 3. Now that you have your own repository, clone it using `git clone`
> 4. Make a branch using `git branch` and switch to that branch using `git checkout`
> `git clone https://github.com/usr/repository/`
> `cd repository/`
> `mate .`
> `git branch test`
> `git checkout test`
> *make changes here*
> `git add file.ext`
> `git commit -m "file changed"`
> `git push --set-upstream origin test`

Now lets go through this code line by line.

> `git clone https://github.com/usr/reposity/`

This line clones the git reposity located at the URL specified into
whatever directory the terminal is currently open to.

> `cd repository/`

Move into the cloned repository

> `mate .`

textmate editor?

> `git branch test`

Create a new branch named `test`.

> `git checkout test`

This either moves into the `test` branch or makes sure we are
in the `test` branch. I am leaning towards the first.

> `git add file.ext`

This command adds `file.ext` to the current commit.

> `git commit -m "file changed"`

Update the commit message to read `file changed`.

> `git push --set-upstream origin test`

Push changes to your repository. Notice that with a fork, we use the
`--set-upstream` flag.

### Time for Pull Request

Now that your fork has been updated, we can proceed with
submitting a pull request.

> 1. Go to your local forked repository on github.com.
> 2. Click **Compare & pull request** to begin the pull request process.

---

## Merge Conflicts

---

Merge conflicts occur when a change occurs in the main branch
making the new branch incompatible for remerge. Good practice
to minimize merge conflicts is to merge the main branch to
your branch to see what changes have been made to the main branch.
Then change your branch to work with changes in main. Then you
may re-merge your branch back to main.

### When They Might Occur

Merge conflicts when you integrate commits from different sources.
Notice that merge conflicts do not just occur when merging branches.

### What They Actually Are

Most of the time, Git is able to merge changes with no problem.
Conflicts occur when there are contradictory changes. Git will
not assume which change you prefer.

### How to Solve Them

You don't have to solve it! You can always undo and start fresh!

#### How to Undo a Conflict and Start Over

> `git merge --abort`

> `git rebase --abort`

#### How to Actually Solve Conflicts

Simply clean up the file.

---

## Merge vs. Rebase

---

Branches are important in Git because it allows you to have
separate containers for your work. There are two main ways
to merge your new code back into your existing code: `merge`
and `rebase`.

### Merge

`merge` Merges branch-B back into branch-A by looking for
three commits. 

1. The common ancestor commit
2. The last commit on branch-A
3. The last commit on branch-B

#### A Fast-Forward Merge

A Fast-Forward Merge occurs when both branch-A and branch-B
share the same history. This is the most simple type of merge.

#### The Merge Commit

The merge commit is a more realistic scenario. This is
different from the commit invoked by the developer. Merge
commit is created automatically by Git and does not wrap
a set of related changes. Its purpose is to connect two
branches.

[The Merge Commit](/Documents/coding/notes/learn-git/merge-commit-graphic.png)


