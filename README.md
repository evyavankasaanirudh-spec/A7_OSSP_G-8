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
