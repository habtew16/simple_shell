# Simple Shell Project

A simple shell project developed in C that provides basic shell functionalities.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- - [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Usage](#usage)
- [Commands](#commands)
- [Built-in Functions](#built-in-functions)
- [File Structure](#file-structure)
- [Author](#author)

## Introduction

The Simple Shell Project is a command-line interpreter implemented in C, providing users with a basic shell environment to execute commands and interact with their system. It is developed as part of a learning exercise to understand shell concepts and C programming.

## Features

- Execute commands from the system's PATH.
- Handle built-in commands like `exit` and `env`.
- Provide basic error handling and user-friendly feedback.
- Supports environment variables and command-line arguments.

## Getting Started

Follow these steps to get started with the Simple Shell Project:

1. **Clone the Repository**: Clone this repository to your local machine using the following command:

   ```bash
   git clone https://github.com/habtew/simple-shell.git
   ```
2. Compilation: Navigate to the project directory and compile the shell using the following command:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```
3. Run the compiled executable
  ```bash
  ./hsh
  ```
### Prerequisites

Before compiling and running the shell, ensure you have the following:

- A C compiler (e.g., GCC)
- A POSIX-compatible operating system (Linux, macOS)

### Compilation

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Functions

### `_is_positive`

Checks if a string represents a positive integer.

### `_atoi`

Converts a string to an integer.

### `execute_line`

Executes a line of commands.

### `split_line`

Splits a line into an array of strings.

### `list_path`

Creates a linked list of directory paths from the PATH environment variable.

### `_setenv`

Sets a new environment variable or modifies an existing one.

### `_which`

Finds the full path of a command.

### `builtin_exit`

Handles the built-in exit command.

### `builtin_env`

Handles the built-in env command.

### `_getenv`

Gets the value of an environment variable.

### `_error`

Prints error messages for command execution.

### `handle_cases`

Handles cases of command execution.

### `add_node_end`

Adds a new node at the end of a directory list.

### `print_num`

Prints a number followed by a newline.

### `_strlen`

Calculates the length of a string.

### `_strcat`

Concatenates two strings.

### `_strdup`

Duplicates a string.

### `_strcmp`

Compares two strings.

### `free_loop`

Frees a loop of pointers.

### `free_list`

Frees a linked list of directory paths.

### `_strncpy`

Copies a string up to `n` bytes.

# Commands

## The shell supports standard Unix commands as well as some built-in functions:

Run external commands: `ls`, `echo`, etc.
Built-in commands: `exit`, `env`
Built-in Functions
`exit`: Terminate the shell.
`env`: Display the current environment variables.
File Structure
The file structure of this project is organized as follows:
```bash
.
├── shell.h          # Header file containing function declarations and structures
├── shell.c           # Main entry point of the shell
├── _string.c           # functions used for string operations
├── helper_functions.c # Implementation of various helper functions
├── builtins.c       # Implementation of built-in command functions
├── _execute.c           # function to execute commands
└── README.md        # Project documentation (you are here)
```

# Author
```
  Habtamu Gebre
  Sophia Odioko
```  

