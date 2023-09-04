#!/opt/homebrew/bin/bash

# variables declared in a function are available 
# to the entire script by default
:'
showuptime(){
    up=$(uptime -p | cut -c4-)
    since=$(uptime -s)
    cat << EOF
-----
This machine has been up for ${up}
It has been running since ${since}
-----
EOF
}
showuptime
'
# the above is bad design because it can
# overwrite variables. bad especially when
# using global variables necessary for the OS
# ** Remember when your dumbass changed $PATH

## -- Better version with local variables -- ##
up="global"         # sample global variable
since="variable"    # sample global variable
echo $up
echo $since
showuptime(){
    local up=$(uptime -p | cut -c4-)    # add 'local' before var name
    local since=$(uptime -s)            # add 'local' before var name
    cat << EOF
-----
This machine has been up for ${up}
It has been running since ${since}
-----
EOF
}
showuptime
echo $up
echo $since
