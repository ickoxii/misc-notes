#!/opt/homebrew/bin/bash

# This script demonstrates how to use positional arguments
# as parameters for a function

showname(){
    echo hello $1
}

showname Icko
