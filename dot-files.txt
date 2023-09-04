- .files are configuration files for your various applications

- they are stored in the home directory '~', '$HOME'

- you can keep these files updated in a git repo to keep configurations
    consistent across devices

- initializing git when you use it for the first time
    git config --global user.name "Your Name"
    git config --global user.email "your@email.com

- use your .noreply email to keep email private when pushing to 
    public repository

sample .zshrc
```
PROMPT='

```

--- Moving all your dot files to one folder ---
# this shows how to move a configuration file to a certain directory
# in order to keep things organized. Then shows how to create a
# symbolic link in the directory where the application would usually
# be reading the config file from. Changes to one file will reflect
# the change in the other file

git config --global user.name "Icko"
git config --global user.email "80863308+ickoxii@users.noreply.github.com"

cd ~                    # move to home directory
mkdir .dotfiles         # create directory
mv .zshrc .dotfiles/    # move config file
# ln -s ~/where/the/file/is ~/where/file/is/expected/to/
ln -s ~/.dotfiles/zshrc ~/.zshrc    # symbolic link
                                    # shows file in two places at the same time
# making a git repo
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

--- Brewfile INFORMATION ---
# tap - where homebrew keeps its own software
# brew - tools to use (usually command line)
# cask - full-blown applications (vs-code, chrome)
brew bat # clone of cat(1) w/ syntax highlighting and git integration
brew exa # modern replacement for ls
brew git # distributed revision control system
brew zsh # UNIX shell (command interpreter)
brew bash # more current version than mac default
# stored in /opt/homebrew/bin/bash
cask "google-chrome"
cask "brave-browser" #maybe
cask "visual-studio-code"


# I COULD HAVE USED BREW TO INSTALL VS CODE??
