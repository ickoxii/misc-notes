#!/opt/homebrew/bin/bash
# modify values in text files using regex

# changes all occurences of 'fly' with 'grasshopper'
sed -i.ORIGINAL 's/fly/grasshopper/g' sedtest.txt

: '
sed 'mode/word_to_find/word_to_replace/scope' file_to_change
sed 'substitute/wordtoreplace/wordtoreplacewith/global' file_to_change
sed -i.ORIGINAL 's/fly/grasshopper/g' sedtest.txt # creates backup file
'
