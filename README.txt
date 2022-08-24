

______________________________________________________________________________________

TO DO

--> signals
--> implement ?$
--> check leaks && valgrind
--> norminette (parse)
--> check if all fds are closed
--> test it

LAST PUSH

-->appending doesnt work --> DONE
--> figure out why exit code 255 -->DONE
--> the redirout in single builtins --> DONE

TESTING

wrote down what isnt same
	BASH											MINISHELL
--> "echo $SHLVL"
	2												=/Users/afenzl/Documents/projects/minishell
--> echo $"$"
	$												$$

_______________________________________________________________________________________

the libft has some extra functions for two dimensional arrays:
-> ft_free2: it frees a split
-> ft_print2: it prints the split -debug
-> ft_splitdup: ft_strdups the whole split
-> ft_splitlen: returns the length of the split

and for env 
-> check_existence will check a split and search for a name until '\0' or '='
	to work with env


