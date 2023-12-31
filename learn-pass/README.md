# Using PASS, The Standard UNIX Password Manager

The information in this video has been taken from the following sources:  

1. [Youtube/Dreams of Code](https://www.youtube.com/watch?v=FhwsfH2TpFA)
2. [Official PASS Website](https://www.passwordstore.org/)
3. [ArchLinux Wiki](https://wiki.archlinux.org/title/Pass)

## Table of Contents

1. [Youtube/Dreams of Code](#youtubedreams-of-code)

## Youtube/Dreams of Code

```zsh
# gpg --full-generate-key
gpg --gen-key
```

PASS uses GnuPG (gpg) under the hood to encrypt passwords. We need our own gpg 
key in order to initialize our password store.

### Using GPG to Get a Key

> gpg --gen-key

The `gpg --gen-key` (or `gpg --full-generate-key` for all features) is a command 
to generate a gpg key-pair to use. You are responsible for this key, so make sure 
it is backed up somewhere, ideally remotely.  

You will be prompted to set a passphrase. This is your password to access your 
personal information (i.e. your stored passwords). Keep this password safe as well.  

Once a passphrase is set, gpg will list a confirmation, including the ID of the 
key you just generated. We use this key to initialize our password store.  

```
pub   rsa3072 2023-12-30 [SC] [expire: 2025-12-30]
      AAAABBBBCCCC111122223333
uid        gpg_name <gpg_email>
sub   rsa3072 2023-12-30 [E] [expires: 2025-12-30]
```

In our example, `AAAABBBBCCCC111122223333` is our gpg key.  

#### Retriving and Editing Our GPG Key

* `gpg -K` - retrieves our gpg key
* `gpg --edit-key AAAABBBBCCCC111122223333` - edits the key `AAAABBBBCCCC111122223333`  

```zsh
# Retrieve and Edit Expiration Date Example
gpg -K
gpg --edit-key AAAABBBBCCCC111122223333
gpg> expire
gpg> save
```

### Initializing Pass

> pass init AAAABBBBCCCC111122223333

### Turn Password Store Into a Git Repository

> pass git init

### Insert an Existing Password

Insert a password into our store using the `pass insert` command.   

> pass insert github/username
> Enter password for github/username:
> Retype password for github/username
> [main a11750e] Add given password for github to store.
>  1 file change, 0 insertions(+), 0 deletions(-)
>  create mode 100644 github/username.gpg

### Generate a Password

> pass generate -c generate github/username 20

We use the `pass generate` command to create a new password and insert it into 
our store. The `-c` flag automatically copies this generated password to the 
clipboard. The integer at the end designates how many characters long our 
password is to be.  

### Organizing Passwords

Under the hood, password store is a file system. We can organize our passwords 
however we like, and directories can similarly be nested to our liking. For 
example, I have the following structure:  

```
email
    school
        username.gpg
    personal
        gmail
            username.gpg
finance
    bank1
        username.gpg
    bank2
        username.gpg
    taxes
        username.gpg
games
    game1
        username.gpg
    game2
        username.gpg
```

In order to access access one of these passwords, we use the path to that password. 
For example, if I started playing a new game and created an account, I could use 
`pass generate -c games/game3/username3.gpg`.  

We can change the file structure and generate new directories by using standard 
commands prefixed by the `pass` command. For example:  

```
# rename/move file or directory
pass mv dir-src/ dir-dest/
# delete a password
pass rm path/to/password
```

### Searching Through Our Passwords

> pass find search-term

We can search through our passwords using the `pass find` command. For example, 
we can look for all of our github passwords using `pass find github`.   

***POTENTIAL VULNERABILITY***  

PASS uses the file system to store our files under the hood. Because the filename 
is viewable, and if storing in a github repo, then using an email or username as 
the filename would leak credentials. Therefore, it is recommended to use another 
naming scheme to keep your files safe and organized.   

### Adding Meta Data

We can edit a password using the `pass edit` command, followed by the path to 
the password we want to edit. A text editor will be opened up, and we can simply 
add our meta data (usernames, security questions, etc). The entire file is 
encrypted, so our meta data is safe here (relatively). 

### Searching With Meta Data

Suppose we hastily created a new password but we forget what we named it. We can 
use `pass grep` to search through all our encrypted files to find a search term. 
For example, we created a password and added the website name in our meta-data.  
```
password_here
URL: website.com
Date Created: 12-30-2023
```

We can use `pass grep website.com` and it will return the file path, as well as 
printing the line contiaining the search term.  
```
path/to/password:
URL: website.com
```

If we don't even remember the email, we can search for all of our emails: 
`pass grep email:`  

### Retrieving Passwords

Print the password file to terminal using `pass show`  

> pass show path/to/password

Copy the first line of the password file (it should be the password) to the 
clipboard using the `-c` flag.  

> pass show -c path/to/password

### Removing a Password

> pass rm path/to/password

### Moving/Renaming a Password

> pass mv intial/path/to/oldpassword changed/path/to/newpassword

### Using Git Commands

Prefix our git command with `pass`  

> pass git status

### Creating a Remote Git Repository

> # Initialize the remote repo
> pass git remote add origin git@github.com:username/repo-name.git
> # Push our repository
> pass git push origin main

### Retriving Passwords From Another Environment

> # Retrieve our passwords from another environment
> git clone git@github.com:username/repo-name.git .password-store  

Since we are on a new machine, we don't yet have the gpg key to decrypt our passwords. 
To fix this, go back to the initial machine, and create an `exported-keys` 
directory.  

```zsh
mkdir exported-keys
cd exported-keys
# Create the file to export
gpg --output public.pgp --armor --export your-gpg-associated@email.com
# Actually export that ho
gpg --output private.pgp --armor --export-secret-key your-gpg-associated@email.com
```

Now, we can go back over to our other machine and transfer the key via ssh. This 
example uses `scp` to connect to ssh.  

```zsh
scp -r your-ssh-associated@email.com:exported-keys .
cd exported-keys
ls
# Import our private key
gpg --import private.pgp # You will be prompted to enter your gpg master password
# Import the public key
gpg --import public.pgp
```

We should now be able to use `pass show` to decrypt and show our passwords.  

#### Upgrading the Trust Level of Public Key

We will need to upgrade the trust level of the public key in order to encrypt 
new passwords on our new machine. Do this using the `gpg --edit-key` command on 
our key. (You can use `gpg --edit-key gpg-key-id`, or `gpg --edit-key your-associated-gpg@email.com`)  

> gpg --edit-key your-associated-gpg@email.com
> gpg> trust
> Your decision? 5
> Do you really want to set this key to ultimate trust? (y/N) y
> gpg> save

### Extra Security

#### Set Environment Variables

Set an environment variable to avoid accidentally pasting your secret key into 
your terminal. This is bad, as it can remain in your shell history for a long 
time if done incorrectly.  

> export GITHUB_TOKEN=$(pass show github/api/token)

#### Secure API Commands That Require a Token

Create an alias to set any access credentials as part of that command, which is 
much more secure than keeping them in a file.  

> # CLI command that requires access token
> aws lambda list-functions --region=us-east-1
> # Set the alias to get the credentials
> alias aws="AWS_ACCESS_KEY_ID=$(pass show aws/access_id) AWS_SECRET_ACCESS_KEY=$(pass show aws/access_token) aws"
> # Now we can use the CLI tools that require authentication automatically
> aws lambda list-functions --region=us-east-1

### Accessing PASS Outside of the Terminal

A large compilation of supporting software, gui, plug-ins, and extensions can be 
found here: <https://github.com/tijn/awesome-password-store>  

Below is a condensed version for my personal use:  

1. Browser plug-ins
    * [browserpass](https://github.com/browserpass/browserpass-extension): 
      Chrome and Firefox browser extension for pass
2. GUI for all major operating systems
    * [pass-for-macOS](https://github.com/adur1990/Pass-for-macOS): macOS client
    * [pass4win](https://github.com/mbos/Pass4Win): windows pass client
3. Apps for mobile devices
    * [passforios](https://github.com/mssun/passforios): iOS pass client
4. Extra plug-ins for more functionality
    * [pass-git-helper](https://github.com/languitar/pass-git-helper): git 
      credential helper interfacing with pass
    * [pass-zsh-completion](https://github.com/ninrod/pass-zsh-completion): 
      pass zsh completion plugin
5. CLI add-ons
    * [gopass](https://github.com/cortex/gopass): Simple UI for password-store (UNMAINTAINED)
    * [gopass-tui](https://github.com/leitzler/gopass-tui): Terminal UI for pass/gopass
