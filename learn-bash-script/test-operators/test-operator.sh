#!/opt/homebrew/bin/bash

# test
# takes in a few arguments and determines if true or not
# can use 'test' or '[]'
[ hello = hello ] # evaluates to true
echo $?         # prints 0 (value of expression)

[ 1 = 0 ]
echo $?         # prints 1 (value of expression)

# operator -eq
# treats values as numerical
[ 1 -eq 1 ]
