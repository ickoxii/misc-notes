# .dot-files

Dot-files are files prefixed with a `.` (period). Any file prefixed with a 
period is hidden by default on macOS. In finder, you can show these hidden 
files using `Command + Shift + .`. In the terminal, you can show hidden files 
using the `-a` flag with the `ls` command, i.e. `ls -a`.  

Dot-files are typically configuration files for your various applications, 
and are usually stored in the home directory (`~`, `$HOME`), in a `~/.config/` 
folder, or in a `~/.APPLICATION_NAME/` folder.  

You can keep these files updated in a remote git repository to keep your 
configurations consistent accross devices.  

***NOTE***: you can use your .noreply github email to keep your email private 
when pushing to a public github repository. 


## Consolidating your Dot-files

As stated earlier, applications may read there respective dot-files from a 
multitude of different directories. This can make maintaining all your 
dot-files a hassle. To combat this, we can keep all of our dot-files in a 
single directory, then create symbolic links to link each dot-file to 
the location where the application expects to read the dot-file from.

### Creating a sym-link

There are two types of links, soft links and hard links. In our configuration, 
we will utilize soft links (symbolic links, or sym-links).

#### Hard Links

Imagine you have two pointers pointing to the same memory location.

```cpp
int value = 69;
int *ptr1 = &value;
int *ptr2 = &value;
```

Both `ptr1` and `ptr2` point to the same memory location, much like how 
a hard link points to the same *inode* (data structure in a file system 
that represents a file) as the original file.  

When you create a hard link, you are essentially creating a new directory 
entry that points to the same inode as the original file. Thus, both the 
original file and the hard link effectively are references to the same data. 
Deleting one does not affect the other, and modifications through one 
reflect in the other. However, if you delete all hard links (including 
the original name) to an inode, the inode (and its associated storage) 
is deallocated.  

#### Soft Links (Sym-Links)

A soft link, on the other hand, is more like a pointer to a file path, 
rather than the actual content of the file.  

Consider a pointer to a value:

```cpp
int *ptr1 = new int(69);

delete ptr1;

std::cout << *ptr1 << "\n";
```

Consider a pointer to memory. We deallocate that memory using `delete`, 
then try to reaccess that memory.  

A symbolic link is a separate file that points to another file by storing 
its path. If the target file is moved, renamed, or deleted, the sym-link 
doesn't automatically update to follow it, leading to a "dangling" link.  

In our cpp example, `ptr1` is like a pointer to our file. Imagine the 
literal value `69` to be our actual file. Deallocating `ptr1` using `delete` 
is parallel to a move, rename, or deletion of our original file. This 
results in our sym-link, (`ptr1` in our example) to be "dangling". 

#### Creating a sym-link of our Dot-file

```bash
cd ~                    # move to home directory
mkdir .dotfiles         # create directory
mv .zshrc .dotfiles/    # move config file
# ln -s ~/where/the/file/is ~/where/file/is/expected/to/
ln -s ~/.dotfiles/zshrc ~/.zshrc    # symbolic link
                                    # shows file in two places at the same time
```

## Making a Git Repository

To be completely fucking honest, I don't know where I copied the below code 
but I know of better ways (I think) to do it now...  

```bash
cd .dotfiles
git clone git@github.com:ssh-goes-here.git ~/.dotfiles
git add .config .files .here
git commit -m "Add .config and .files and .here"
git log # previous git commands?
# git commit --amend --reset-author # edit contents of commit in vim
git commit --amend --reset-author --no-edit # we dont want to actually edit 
git add README.md
brew bundle dump --describe # prints list of brew installed applications to a file names 'Brewfile'
git add Brewfile
```

## Storing our Homebrew Information

Since we may (or may not) install a bunch of packages using brew, we can use 
the command `brew bundle dump` (or `brew bundle dump --force` if Brewfile 
already exists in the currect directory) to list all of our brew installed 
packages.  

NOTE: Homebrew can be installed by running the following command in your
terminal

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- tap - where homebrew keeps its own software
- brew - tools to use (usually command line)
- cask - full-blown applications (vs-code, chrome)

Here is an example Brewfile (the output of `brew bundle dump`). The output 
will differ based on which packages you have installed. 

```
brew bat # clone of cat(1) w/ syntax highlighting and git integration
brew exa # modern replacement for ls
brew git # distributed revision control system
brew zsh # UNIX shell (command interpreter)
brew bash # more current version than mac default
# stored in /opt/homebrew/bin/bash
cask "google-chrome"
cask "brave-browser" #maybe
cask "visual-studio-code"
```
