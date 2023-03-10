# minishell
This is a project for [42Heilbronn](https://www.42heilbronn.de/en/curriculum/) school's curriculum.

The goal of the project is to write a program __creating a simple shell__, that provides a command-line interface for users to interact with the operating system.

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
   - __cd__ with only a relative or absolute path
   - __pwd__
   - __export__
   - __unset__
   - __env__
   - __exit__

## Description
**run _`make`_**

The program will be executed as follows:

__`./minishell`__

now just use it as if it would be Bash.

## What i learned:
+ deeper knowledge on how `bash's behavior`
+ handling `signals`, such as SIGINT or SIGQUIT
+ how and when enviroment variables are expanded
+ how to structure bigger projects

