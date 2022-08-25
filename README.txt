

______________________________________________________________________________________

TO DO
PARSING:
--> implement ?$
--> fix expansion
--> using only neccassary tokens
--> norminette

EXEC:
--> signals
--> check leaks && valgrind
--> test it

LAST PUSH

--> check if all fds are closed --> DONE
--> appending doesnt work --> DONE
--> figure out why exit code 255 -->DONE
--> the redirout in single builtins --> DONE


TESTING

wrote down what isnt same
	BASH											MINISHELL
--> "echo $SHLVL"
	2												=/Users/afenzl/Documents/projects/minishell
--> echo $"$"
	$												$$
--> env | clear | env cat -e >out
	^[[H^[[2J										the enviroment
	(dont get it)
--> echo "$_="
	_==												$_=
--> echo $"_="
	$_=												_=
--> echo $_ (the last executed command)
	env												$_
	ls..
	>>rn the value of '_' is _=/usr/bin/env on default
	since you mostly check it over env --> last executed cmd is env
	but if you check it witch echo $_ its gonna show the last cmd
_______________________________________________________________________________________

the libft has some extra functions for two dimensional arrays:
-> ft_free2: it frees a split
-> ft_print2: it prints the split -debug
-> ft_splitdup: ft_strdups the whole split
-> ft_splitlen: returns the length of the split

and for env 
-> check_existence will check a split and search for a name until '\0' or '='
	to work with env


