#!/opt/homebrew/bin/bash

MY_FIRST_LIST=(one two three four five)

# range based loop
# count length of each word in array by piping each word into the wc -c command
for item in ${MY_FIRST_LIST[@]}; do
    echo -n $item | wc -c;
done


