# Debugging C/C++ with lldb

All code blocks are commands to be run in a shell unless otherwise stated. 
If appended with `(lldb)`, the command is run from inside an lldb process.

[Debugging C/C++ with LLDB Tutorial](https://www.youtube.com/watch?v=2GV0K9Y2MKA&t=440s)

## Chapters

* [Compiling Your Program](#compiling-your-program)
* [Starting LLDB](#starting-lldb)
    * [With Command Line Arguments](#with-args)
    * [With Input Redirection](#with-input-redirection)
    * [With Output Redirection](#with-output-redirection)
* [Setting Breakpoints](#setting-breakpoints)
    * [Breakpoints with Symbols](#breakpoints-with-symbols)
    * [Manipulating Breakpoints](#manipulating-breakpoints)
* [Stepping Around](#stepping-around)
* [Inspecting Variables](#inspecting-variables)
* [Backtrace and Frames](#backtrace-and-frames)
* [Watchpoints](#watchpoints)


```bash
g++ -g main.cpp -o a.out
lldb a.out
```

## Compiling Your Program

`g++ -g main.cpp -o a.out`  

We want to compile our program with the `-g` flag to enable debug mode

## Starting LLDB

```bash
# Start lldb process with the given executable
lldb a.out
# Run process with run
(lldb) run
# Or, run process with r
(lldb) r
````

### With args

If you call a program like `./a.out argument1`, the equivalent in lldb is:

```bash
# From command line
lldb -- a.out argument1
# Or, from inside lldb
(lldb) settings set --target.run-args "argument1"
```

### With input redirection

If you call a program like `./a.out < /path/to/input`, the equivalent in
lldb is:

```bash
lldb a.out
(lldb) settings set -- target.input-path "/path/to/input"
```

### With output redirection

Not tested yet, but assuming this works based in input redirection

```bash
lldb a.out
(lldb) settings set -- target.output-path "/path/to/output"
```

## Setting Breakpoints

Breakpoints can be set with any of the following commands. Each successive
command is shorthand for its predecessor.  

```bash
(lldb) break set -f demo.cpp -l #
(lldb) br s -f demo.cpp -l #
(lldb) b demo.cpp : #
```

The `-f` flag allows us to specify a file to set a breakpoint in the specified
file. The `-l` is for specifying the line number at which to set the breakpoint.
`#` is the actual line number the breakpoint will be set to.

### Breakpoints with Symbols

* ***On a function***  
`(lldb) b square(int)`
* ***On a class method***  
`(lldb) b Demo::demo()`  
* ***Inside a namespace***  
`(lldb) b nameSpaceName::function_name(int, int)`  

If we want to pause execution as soon as we run our program, we can set a
breakpoint at main(), i.e. `b main`.

### Manipulating Breakpoints

* ***Listing Breakpoints***

```bash
(lldb) br list
```

* ***Deleting Breakpoints***

```bash
(lldb) br del #
(lldb) br del
```

In this case `#` is the breakpoint number when printing `br list`, not the line
number.

## Stepping Around

|**Stepping Around**|  
|-------------------|  
|**Step Over**|  
|`(lldb) next`|  
|`(lldb) n`|  
|**Step Into**|  
|`(lldb) step`|  
|`(lldb) s`|  
|**Continue**|  
|`(lldb) continue`|  
|`(lldb) c`|  

* **Step Over**: execute the next line of code
    * For example, if we have the line `std::cout << "Hello"`, `next` will 'step
      over' that line and execute it without going into the cout library call
* **Step Into**: step into the function we call
    * For example, if you have a line `int s = area(l);`, `step` will 'step
      into' the `area` function
* **Continue**: execute until the next breakpoint

## Inspecting Variables

|**Inspecting Variables**|  
|---------------------------|  
|**Print Variable Contents**|  
|`(lldb) p varName`|  
|**Frame Variables**|  
|`(lldb) frame variable`|  
|`(lldb) fr v`|  
|**Current Line**|  
|`(lldb) frame select`|  
|`(lldb) fr s`|  

* `p varName` - Prints the value stored in varName
* `frame variable` - Prints all variables on the current stack frame
* `frame select` - Choose a stack frame
    * Frame 0 is always the top of the stack (most recent frame)
    * If you lose where you are (ex. call help function and it clears your
      screen), you can go back to where you were using `fr s`

## Backtrace and Frames

|**Backtrace and Frames**|  
|------------------------|  
|**Backtrace**|  
|`(lldb) bt`|  
|**Switching Frames**|  
|`(lldb) frame select #`|  
|`(lldb) f #`|  

* `(lldb) bt` - back trace prints a list of the current function call stack
* `(lldb) frame select #` - selects frame '#'

## Watchpoints

***Program must be running in order to set the watch point***. This is so that
the debugger knows the address that variable is stored at.  

|**Global Variable**|  
|-----------------------------------------------------------------------------|  
|`(lldb) watchpoint set variable globalVariable`|  
|`(lldb) watchpoint set variable -w read | write | read_write globalVariable`|  
|**Member Variable**|  
|`(lldb) b main)`|  
|`(lldb) w s v d.memberVar`|  

Watchpoints are used to monitor and trigger breakpoints when a specified memory
location is modified. We can specify when to trigger this breakpoint using the
specifiers:  
* `read` - set breakpoint when variable is read from  
* `write` - set breakpoint when variable is written to  
* `read_write` - set breakpoint when variable is read from or written to  
The shorthand for this is `w s v` -- [W]atchpoint [S]et [V]ariable.

## Terminating

|**Termination**|  
|---------------|  
|**Kill Process**|  
|`(lldb) kill`|  
|**Exiting**|  
|`(lldb) quit`|  
|`CTRL-D`|  

Kill the process first using `kill`, then exit the lldb process using `quit`.
