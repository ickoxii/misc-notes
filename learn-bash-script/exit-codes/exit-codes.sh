#!/opt/homebrew/bin/bash
# call using
# ./exit.sh ickoxii

showname(){
    echo hello $1
    if [ ${1,,} = ickoxii ]; then
        return 0
    else
        return 1
    fi
}


showname $1
if [ $? = 1 ]; then
    echo "Someone unknown called the function!"
fi
