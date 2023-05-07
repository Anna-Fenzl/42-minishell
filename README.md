# minishell
This is a project for [42Heilbronn](https://www.42heilbronn.de/en/curriculum/) school's curriculum.

The goal of this team-project is to write a program __creating a simple shell__, that provides a command-line interface for users to interact with the operating system. I was responsible for the execution part, my partner [Anna Iarinov](https://github.com/iarinov) did the parser.

## Features
+ Display a `prompt` when waiting for a new command
+ Have a `working history`
+ Search and launch the right executable based on the PATH variable or `using a relative or absolute path`
+ Handle single and double `quotes`
+ Implement `redirections` (<, >, <<, >>)
+ Implement `pipes` (|)
+ Handle `environment variables` ($ followed by a sequence of characters) which should expand to their values
+ Handle $? which should expand to the `exit status` of the most recently executed foreground pipeline
+ Handle the `signals` ctrl-C, ctrl-D and ctrl-\ which should behave like in bash
+ `Built-in commands`:
   - __echo__ with option -n
   - __cd__ with a relative or absolute path
   - __pwd__
   - __export__
   - __unset__
   - __env__
   - __exit__

## Description
**run _`make`_**

Before running minishell make sure that you have readline library installed and found by the Makefile.
The program will be executed as follows:

__`./minishell`__

## What i learned
+ What are `signals` and how to use them
+ `Redirections` in bash
+ `Variable expansion` in bash
+ How does the bash interpret `single and double quotes`
+ What's a `parser`
+ Usage of `builtin commands of` bash
