# Using TMUX

## Table of Contents

1. [Installation](#installation)
2. [Launching TMUX](#launching-tmux)
3. [TMUX Controls](#tmux-controls)
4. [Customization](#customization)
5. [New Windows](#new-windows)
6. 

## Installation

Use your preferred package manager

```bash
# homebrew
brew install tmux
```

## Launching TMUX

```bash
tmux
```

Using `tmux` in the command line launches a new tmux session.

## TMUX Controls

Controls in tmux are based on a <leader>+<command> setup. The default leader 
in tmux is <Ctrl+b>. To split a pane, for example (<command> = '%'), we press 
our leader key <Ctrl+b> followed by our command to split pane <'%'>. This is 
commonly denoted as `<leader>+%`.  

## Customization  

You can customize your tmux configuration and keybinds in a `~/.tmux.conf` file. 
Here is my configuration: <https://github.com/ickoxii/dot-files/blob/main/tmux/.tmux.conf>  

The main things I change are changing the leader key from <Ctrl-b> to <Ctrl-a>, 
changing the split pane keys from `%` to `v` (vertical), and from `"` to `s` 
(horizontal). I also bind the `hjkl` keys to navigate between panes (vim-like 
navigation).  

## New Windows 

You can split each window into a different task, with each window containing 
multiple panes. The default control for this is `<leader>+c`.  

Each new window is numbered sequentially starting from 0. We navigate to a 
window by pressing `<leader>` followed by the window number.  

i.e. `<leader>+0> to go to window 0, `<leader>+4` to go to window 4, etc.

## Renaming Windows

`<leader>+,` - Renames the current window  

Renaming our windows gives a little more specificity as to what we are using 
each window for. Otherwise, we might have 4 windows all saying 'bash', and we 
have to use more mental overhead to remember which window we use for what. Now, 
we can rename windows to whatever we want. i.e. Name windows 'git', 'docker', 
'testing', 'config', etc.

## Exiting a Window

`exit`  

Pretty self explanatory.

## Listing all Running Sessions

`tmux ls`  

Lists all active tmux sessions (listed sequentially starting from 0) with the 
number of windows per session and when the session was created. 

## Detaching/Reattaching/Renaming to Sessions

* `<leader>+d` - Detach from the current tmux session
* `tmux ls` - List all active tmux sessions
* `tmux attach -t 0` - Attach to target session 0
    * `-t` - The -t flag allows us to specify a target. In this case, target 
      session 0.
* `tmux rename-session -t 0 git`
    * Renames session 0 to 'git'
* `tmux new -s docker`
    * Begins a new tmux session with the session name 'docker'
* `tmux kill-session -t target_session`
    * Kills the target session

TMUX sessions persist until system reboot or killed.
