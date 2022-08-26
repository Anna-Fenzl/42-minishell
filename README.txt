

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

LAST PUSH
--> test it (theres a tester now)
--> removed opening infile in transform
--> fixed exitcode with broken pipes
--> redid the pipes
--> check leaks && valgrind

TESTING
	run the tester with ./tester.sh m
	valgrind with					v

	current test results:
	STD_OUT: 66  STD_ERR: 19  EXIT_CODE: 2
	min possible errors:
	STD_OUT: 262  STD_ERR: 275  EXIT_CODE: 385 
_______________________________________________________________________________________

the libft has some extra functions for two dimensional arrays:
-> ft_free2: it frees a split
-> ft_print2: it prints the split -debug
-> ft_splitdup: ft_strdups the whole split
-> ft_splitlen: returns the length of the split

and for env 
-> check_existence will check a split and search for a name until '\0' or '='
	to work with env
