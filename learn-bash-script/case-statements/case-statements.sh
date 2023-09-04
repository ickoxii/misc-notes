#!/opt/homebrew/bin/bash

# case statements
# better than ifelifelse when checking for multiple values

# this code does the same as the script in /learn-bash-script/if-elif-else/

# defining multiple options in condition (can also be used in ifelifelse)
case ${1,,} in
    # in case statement, '|' is used as symbol for multiple options, NOT pipe
    ickoxii | administrator)
        echo "Hello, you're the boss here!"
        ;; # end this option
    help) # define next option
        echo "Just enter your username!"
    *) # default case
        echo "Hello there. You're not the boss of me. Enter a valid user"
esac # close by spelling case backwards
