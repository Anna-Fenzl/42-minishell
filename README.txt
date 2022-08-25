

______________________________________________________________________________________

TO DO
PARSING:
--> implement ?$
--> fix expansion
--> using only neccassary tokens
--> norminette
--> "| test" is not seen as a syntax error

EXEC:
--> signals
--> STD_ERR in exit
--> execute it even if you cant open invalgrfile(more than one cmd)
	"<dklj ls | ls"
--> test it (theres a tester now)

LAST PUSH
--> check leaks && valgrind


TESTING

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


