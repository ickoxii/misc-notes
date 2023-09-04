#!/opt/homebrew/bin/bash

# this is just for commands to be used in command lines
MY_FIRST_LIST=(one two three four five)

# this will just print the first element
echo $MY_FIRST_LIST

# print the entire list
echo ${MY_FIRST_LIST[@]}

# index reference
echo ${MY_FIRST_LIST[0]}
