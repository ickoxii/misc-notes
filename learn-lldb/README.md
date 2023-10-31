# Using lldb to Debug C++ on MacOS

## Getting Started

There are a few things you need to do before you actaully use lldb to begin
debugging your program. 

### Compiling Your Program with `-g`

You can compile your program without the -g flag, but then some information may
be lost when debugging, such as variable names and line numbers.

    g++ -o a.out proj.cpp -g

### Dumping a Core

Dumping a core is not always necessary, but can give you more information that
you would typically receive. Cores on MacOS are typically dumped in the /cores/
directory. The following steps describe how to dump your core in your local
working directory instead.

On MacOS, we can set the maximum core dump size to unlimited. This can be done
using:

    ulimit -c unlimited

1. **Attach `lldb` to the process**:

    lldb -o [PID]

Where `[PID]` is the process ID of the process you wish to dump. To find the PID
of the process we wish to dump, we can use the `pgrep` command (process grep)
while our executable is running. We can use ^Z (ctrl+Z) to suspend the process
when we begin running it and use another terminal window to `pgrep` for our PID.

Instead, we can start running our executable while it is already in the suspend
state. To do this on macOS, you can use the command

    (sleep 1 && kill -STOP $1) & ./a.out &

After using this command, we can verify that our process has stopped using the
`jobs` command.

2. **Once in `lldb`, generate the core dump**:

    process save-core ./core_filename

3. **Exit `lldb`**:

    quit

This will produce the core dump in your current directory with the name you
specified. 

Bear in mind that this method does pause the process briefly while the core is
being saved.

## Debugging with lldb

Now that we have dumped out core, we can run `lldb` as usual, with some modified
steps in order to link the core to our executable.

### Linking Your Core File

1. **Load core into `lldb` alongside original binary for debugging**:

    lldb <path-to-binary> -c <path-to-core-dump>

i.e.
    
    lldb ./my\_program -c ./core

2. **Debugging the Core Dump**:

Once the core is loaded, you can use regular `lldb` commands to inspect the
state of the program when it crashed.

## `lldb` and its Commands

## Input Redirection with `lldb`

Once we begin an `lldb` process, we can emulate `./executable_name <
/path/to/input.txt` using the `run -- < /path/to/input.txt` command.

```bash
lldb ./executable_name
(lldb) run -- < /path/to/input.txt
(lldb) n
(lldb) quit
```

`--` separates lldb commands, so I assume you can actually run `(lldb) run` and
`(lldb) < /path/to/input.txt` as separate commands.

Note: when we use input redirection while invoking the process (i.e. `lldb
./exec_name < /path/to/input.txt`), lldb reads the file as lldb commands and 
attempts to execute them instead of letting the executable read the file as
input.  

I suppose this could be useful to automate the input redirection part. We can
have a file that contains `run -- < /path/to/input.txt` command, and use that 
in the 'args' field of the launch.json file for vscode debugging.

### Addendum

Yeah so this shit dont work. Use this instead:

```bash
lldb ./exec
(lldb) settings set target.input-path /path/to/input
(lldb) run
```

When trying to use this in vs code tho... doesnt exactly work.
