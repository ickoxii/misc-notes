#!/opt/homebrew/bin/bash

# -- PIPING -- #
# Sends the output of one command as the input of another command

echo Hello there | grep there

# ex: want to filter certain files out of a directory when viewing
ls -l $HOME | grep bash
# takes output of ls command into the grep (search?) command


## -- OUTPUT REDIRECTION -- ##
# Sending output from a command to a file
# ie. logging to a logfile, dynamically create config files
echo Hello World! > hello.txt       # overwrites file
echo Hello World! >> hello.txt      # appends to file

cat hello.txt

echo Good day to you >> hello.txt

cat hello.txt

## -- INPUT REDIRECTION -- ##
# pass in file name as positional argument
wc -w hello.txt     # word count

# pass in contents of file
wc -w < hello.txt   # now uses contents of file instead of 
                    # name of file as positional argument

# supply multiple lines with <<
cat << EOF
I will
write some
text here
until
EOF

cat << nextDelimiter
next set
of words
nextDelimiter

# feeding a string into a command
# string must be between double quotes
wc -w <<< "Hello there wordcount!"
