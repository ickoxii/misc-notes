# Vim Shortcuts and More

This contains information found in vimtutor provided by vim, consolidated in one
place.

## Introduction



### Moving the Cursor

To move the cursor, press the h, j, k, l keys.  

h - left  
j - down  
k - up  
l - right  
b - previous beginning of word before the cursor
e - next end of word after the cursor
w - first character of word after the cursor
0 - beginning of line
$ - end of line
gg - beginning of file
G - end of file

### Exiting ViM

Exiting the program is done with the `:q` command.

```
:q
```

To force quit and discard all changes, add a `!`.

```
:q!
```

To save and quit:

```
:wq
```

### Text Editing

|Operator|Description|
|:-------|:----------|
|x|Delete character at cursor|
|d|Delete|
|i|Insert at the cursor|
|a|Insert after the cursor|

### On Operators and Motions

Many commands that change text are made from an operator and a motion. The
format for a delete command with the delete operator is as follows:

> d motion

Where:  
d - is the delete operator  
motion - is what the operator will operator on (listed below).  

A short list of motions:
w - until start of next word, EXCLUDING its first character.
e - to the end of current word, INCLUDING its last character.
$ - to the end of the line, INCLUDING the last character.
0 - to the beginning of the line, INCLUDING the first character.
d - delete the whole line (i.e. `dd`)

#### Using Counts for a Motion

Typing a number before a motion repeats that motion that many times. This can be
done with the motion as is, or when the motion is acting on an operator. i.e. 2j
moves 2 lines down, d2e deletes the next two words until the end of word.

#### Operating on a Line

We use `dd` to delete a whole line. In general, doubling to operate on a line
works for other operators mentioned below.

## The Undo Command

u - undo the last command(s)  
U - fix a whole line  

### The Redo Command

CTRL-r - redo the last undo you did

## The Put Command  

p - put previous deleted text after the cursor  

## The Replace Command

rx - replace the character at the cursor with 'x'.

## The Change Operator

Performs a delete operation using the same motions, then puts you in insert
mode.  

```
c [number] motion
```

ce - change (delete) until end of word, then goes to insert mode  
c$ - change (delete) until end of line, then goes into insert mode  

## Cursor Location and File Status

Use `CTRL-g` to show your location in the file and the file status. Type G to
move to a line in the file. 

G - moves you to bottom of the file  
gg - moves you to the start of the file  
:x - moves you to line 'x'  

## The Search Command

Type `/` followed by a phrase to search for the phrase.  
To search for a phrase in the backwards direction, use `?` instead.  
To search for the same phrase again, simply type `n`.  
To search for the phrase in the opposite direction, type `N`.  
To go back to where you came from, press `CTRL-o` (repeat to go back further)  
`CTRL-i` goes forward.  

### Matching Parentheses Search

`%` - find a matching (), [], or {}.  

## The Substitute Command

`:s/old/new` to substitute 'old' with 'new'. We can modify the substitute
command and add flags at the end to change the functionality.  

For example, `:s/old/new` would only change the first occurence of 'old'. In
order to change 'old' across the whole file, or globally, we can use
`:s/old/new/g` instead.  

### More Complicated Substitutes

To change every occurrence of a character string between two lines,
`:#,#s/old/new/g` - #,# are the line numbers of the range in which substitution
    is to be done.
`:%s/old/new/g` -  change every occurrence in the whole file.
`:%s/old/new/gc` - change every occurrence in the whole file, with a prompt
    whether to substitute or not.

## Executing External Commands

Type `:!` followed by an external command to execute that command.

i.e. `:!ls` to list the current directory

The `!` allows you to execute any external shell command, with arguments as well

## More on Writing Files

To save changes made to the text, type `:w FILENAME`. where FILENAME is a name
that does not exist yet. If this file already exists, you can just use `:w`
instead, or, use `:w! FILENAME` to force overwrite the file with that given
name.

### Selecting Text to Write (Visual Mode)

To save part of the file, type `v motion :w FILENAME`. `v` places you visual
mode, which you can then use motions to select the text you want. `:w FILENAME`
then takes the text marked in visual mode and writes it to a file of the given
name.

## Retrieving and Mergin Files

To insert the contents of a file at the cursor, type `:r FILENAME`.   

Apparently you can somehow pipe other things into :r, like `:r !dir` reads the
output of the dir command and puts it below the cursor position.  

## The Open Command

Type `o` to open a line below the cursoe and place you in Insert mode. To open a
line ABOVE the cursor instead, use a capital o, i.e. `O`. 

## The Append Command

The append command `a` allows you to insert text AFTER the cursor.

## Another Way to Replace

The capital r `R` is used to replace more than one character. This allows you to
type and replace each character until `esc` is pressed.

## Copy and Paste Test (Yank)

Use `y` to copy text and `p` to paste it. Enter the visual block using `v` and
use motions to select the text you want to yank. Once the selected text is
yanked, you can use `p` to place the text at the cursor.  

`y` can also be used as an operator:  
yw - yank one word  
yy - yank the entire line  
y$ - yank until end of line  
etc.  

## Set Option

Set an option so a search or substitute ignores case.  

`:set ic` - ignore case when searching or substitute  
`:set noic` - disable ignore case (return to default)
`:set hls is` - sets 'hlsearch' and 'incsearch' options
`:nohlsearch` or `:noh` - remove highliting of search matches
`\c` - ignore case for one command. i.e. doesn't change global setting  
> /searchPhrase\c

## Getting Help

1. Press the <HELP> key (if you have one)
2. Press the <F1> key (if you have one)
3. type :help <ENTER> (or :help command <ENTER>)

```
:help w
:help c_CTRL_D
:help insert-index
:help user-manual
```

## Create a Startup Script

Vim has many more features than Vi, but many are disabled by default. To start
using more features you should create a "vimrc" file.

1. Start editing the "vimrc" file. This depends on your system:
`:e ~/.vimrc`           for Unix  
`:e !/_vimrc`           for Windows  

2. Now read the example "vimrc" file contents:
`:r $VIMRUNTIME/vimrc_example.vim`

3. Write the file with:
`:w`

## Completion

Command line completion with `CTRL-d` and `<TAB>`.  

1. Make sure Vim is not in compatible mode: `:set nocp`  
2. Look what files exist in the directory: `:!ls` or `:!dir`
3. Type the start of a command: `:e`
4. Press CTRL-d and Vim will show a list of commands that start with "e".
5. Type `d<TAB>` and Vim will complete the command name to ":edit".
6. Now add a space and the start of an existing file name: `:edit FIL`
7. Press <TAB>. Vim will complete the name (if it is unique).

Completion works for many commands. Just try pressing CTRL-d and <TAB>. It is
especially useful for :help.
