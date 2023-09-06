# compile with '-g' to compile in debug mode
g++ -g

# run lldb on executable
lldb a.out

# put a breakpoint at any function you want to debug
b main

# run the program
run

# move through the program with next
n

# use 'enter' to repeat the last command

# look at variables with
print [var_name]

# print all variables (frame all variables)
fr v

# exit lldb
exit
