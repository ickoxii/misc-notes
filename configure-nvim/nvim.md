# Installing and Configuring nvim for MacOS

Taken from: [Effective Neovim: Instant IDE](https://www.youtube.com/watch?v=stqUbv-5u2s)

## Table of contents

1. [Install nvim](#install-nvim)
2. [Create Configuration Folder](#create-configuration-folder)
3. [Yoink Someones Config](#grab-someone-elses-config-lmao)

## Command Line From de Beninging

```bash
brew install nvim

mkdir -p ~/.config/nvim
cd ~/.config.nvim

touch init.lua
vim init.lua
# Copy initial config file into init.lua
```

## Install nvim

```bash
brew install nvim
```

## Create Configuration Folder

```bash
mkdir -p ~/.config/nvim
cd ~/.config/nvim
```

## Grab Someone Elses Config lmao

[kickstart.nvim](https://github.com/nvim-lua/kickstart.nvim)  

[init.lua](https://github.com/nvim-lua/kickstart.nvim/blob/master/init.lua)  

Create an `init.lua` file inside `.config/nvim` and copy-paste the contents
over.


