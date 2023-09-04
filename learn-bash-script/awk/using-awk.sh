#!/opt/homebrew/bin/bash

# AWK 
# filters file contents or outputs of a command

# create text file
echo one two three > test.txt

## -- default mode, uses space as delimiter
# get the first element in file
awk '{print $1}' test.txt # prints 'one'

# get the second element in file
awk '{print $2}' test.txt # prints 'two'


# -- other delimiters
echo one,two,three > testcsv.csv

# -F to specify delimiter?
awk -F, '{print $1}' testcsv.csv # prints 'one'
awk -F, '{print $2}' testcsv.csv # prints 'two'


# -- piping into awk
# grab 5th word
echo "Just get this word: Hello" | awk '{print $5}' | cut -c2

# split at colon symbol
echo "Just get this word: Hello" | awk -F: '{pring $2}' | cut -c2

# note: 'cut' just cuts out the space. idk how


