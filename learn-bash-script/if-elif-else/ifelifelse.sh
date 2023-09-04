#!/opt/homebrew/bin/bash

: '
if [ condition ]; then
    ...
elif [ condition ]; then
    ...
else
    ...
fi
'

: '
this script takes in a positional argument
we check if the first positional argument is equal to the value we provide
{,,} - parameter expansion, allows us to ignore upper/lower cases when comparing
'
if [ ${1,,} = ickoxii ]; then
    echo "Oh you're the boss here. Welcome!"
elif [ ${1,,} = help ]; then
    echo "Just enter your username, duh!"
else
    echo "I don't know who you are. But you're not the boss of me!"
fi
