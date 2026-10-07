# Linux Process Explorer

Linux Process Explorer is an OSSP project designed to monitor
and manage running processes in a Linux environment.

## Project Description

The project aims to provide a lightweight command-line tool
for viewing process information such as PID, process state,
CPU usage, memory usage, and process priority.

## Week 1 Features

- Interactive REPL loop
- Command handling
- Help command
- Basic project structure
- Makefile-based compilation
- Git repository
- Linux development environment

## Technologies Used

- C
- Linux / Ubuntu
- GCC
- Make
- Git
- GitHub

## Build

```bash
make

## Week 2 Features

- Dynamic command input
- Memory allocation using malloc()
- Automatic buffer expansion using realloc()
- Proper memory cleanup using free()
- Modular input handling using input.c and input.h

## Week 3 Features

- Command parsing using strtok()
- Dynamic argv[] construction
- Modular parser implementation
- NULL-terminated argument vector
- Ready for process execution with execvp()

## Week 4 Features

- Real Linux command execution
- Process creation using fork()
- Command execution using execvp()
- Parent process synchronization using waitpid()
- Error handling using perror()
- Child process execution
- Parent process waits for the child process to finish

## Week 4 System Calls

| System Call | Purpose |
|---|---|
| fork() | Creates a child process |
| execvp() | Executes the entered Linux command |
| waitpid() | Makes the parent wait for the child process |
| perror() | Displays error messages |

## Running the Project

Compile the project:

```bash
make clean
make

## Week 5 Features

- Built-in command support
- `cd` command using `chdir()`
- `pwd` command using `getcwd()`
- `help` command
- `clear` command
- `exit` command
- `env` command
- Environment variable access using `getenv()`
- Built-in commands execute in the parent process
- External commands continue to use `fork()` and `execvp()`

## Week 5 Environment Variables

The project currently displays:

- `HOME` - User home directory
- `USER` - Current username
- `PATH` - Executable search path

## Week 5 Files Added

```text
include/builtin.h
src/builtin.c

## Week 6 Features

- Improved process management
- Modular process execution
- Linux process handling using system calls
- Improved command execution workflow

## Week 7 Features

- Anonymous pipe support
- Two-command pipelines
- Inter-process communication using file descriptors
- `pipe()` system call
- `dup2()` system call
- Pipeline execution using `fork()` and `execvp()`

## Week 8 Features

- Memory leak detection using Valgrind
- Debugging using GDB
- AddressSanitizer (ASan) support
- Defensive memory management
- Improved error handling
- Proper file descriptor and child process management

## Week 8 Debugging Tools

- Valgrind
- GDB
- AddressSanitizer (ASan)

## Week 8 Validation

- Valgrind reports no memory leaks
- Valgrind reports zero errors
- GDB used for program inspection and stack tracing
- ASan build and execution completed successfully
## Week 9 Features

- File descriptor management
- Input redirection using `<`
- Output redirection using `>`
- Append redirection using `>>`
- Error redirection using `2>`
- File operations using `open()`
- File descriptor cleanup using `close()`
- File descriptor duplication using `dup2()`
- Integration of I/O redirection into ShellForge

## Week 9 Files Added

```text
include/redirect.h
src/redirect.c	
## Week 10 Features

- POSIX thread support
- Background monitoring thread
- `pthread_create()`
- `pthread_join()`
- Mutex synchronization
- Race condition demonstration

## Week 10 Validation

- POSIX thread support compiled successfully with `-pthread`
- Background monitoring thread started successfully
- Monitoring message displayed every 10 seconds
- ShellForge remained interactive while the monitoring thread was running
- Week 10 thread implementation tested successfully
