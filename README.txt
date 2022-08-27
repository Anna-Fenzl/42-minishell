

changed exit builtin to write "exit" to STDIN_FILENO

______________________________________________________________________________________

TO DO
PARSING:
--> fix expansion
--> using only neccassary tokens
--> norminette
--> valgrind

--> implement ?$ --> DONE but edge cases with spaces
--> the <> REDIR5 is still considered valid-->DONE
--> "| test" is not seen as a syntax error -->DONE

EXEC:

LAST PUSH
--> uniform returns in syntax_error plus norm
--> fixed builtin strncmp
--> variable expansion in here_doc
--> STD_ERR in exit 
--> new_split in parser
--> made ft_printf_fd for specific error messages


TESTING
	run the tester with ./tester.sh m
	valgrind with					v
	(in docker plus readline must be installed (apt-get install libreadline6 libreadline6-dev))

	current test results:
	STDOUT: 29  STD_ERR: 17  EXIT_CODE: 1
	yesterdays test results:
	STD_OUT: 66  STD_ERR: 19  EXIT_CODE: 2
	min possible errors:
	STD_OUT: 262  STD_ERR: 275  EXIT_CODE: 385 
	in valgrind:
	STD_OUT: 71  STD_ERR: 263  EXIT_CODE: 30

VALGRIND
Invalid write of size 1
==362==    at 0x40744B: ft_substr (in /code/minishell)
==362==    by 0x405AA4: ft_strtrim (in /code/minishell)
==362==    by 0x402511: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
==362==  Address 0x56752c0 is 0 bytes after a block of size 0 alloc'd
==362==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==362==    by 0x407434: ft_substr (in /code/minishell)
==362==    by 0x405AA4: ft_strtrim (in /code/minishell)
==362==    by 0x402511: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
==362== 
==362== Invalid read of size 1
==362==    at 0x40541E: ft_strlen (in /code/minishell)
==362==    by 0x4057DA: ft_strdup (in /code/minishell)
==362==    by 0x402555: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
==362==  Address 0x56752c0 is 0 bytes after a block of size 0 alloc'd
==362==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==362==    by 0x407434: ft_substr (in /code/minishell)
==362==    by 0x405AA4: ft_strtrim (in /code/minishell)
==362==    by 0x402511: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
==362== 
==362== Invalid read of size 1
==362==    at 0x4073C9: ft_memcpy (in /code/minishell)
==362==    by 0x405817: ft_strdup (in /code/minishell)
==362==    by 0x402555: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
==362==  Address 0x56752c0 is 0 bytes after a block of size 0 alloc'd
==362==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==362==    by 0x407434: ft_substr (in /code/minishell)
==362==    by 0x405AA4: ft_strtrim (in /code/minishell)
==362==    by 0x402511: replace_var_in_q (in /code/minishell)
==362==    by 0x4025D4: replace_var_env (in /code/minishell)
==362==    by 0x40263F: parse_lexer (in /code/minishell)
==362==    by 0x4027B4: parse (in /code/minishell)
==362==    by 0x400E2D: minishell (in /code/minishell)
==362==    by 0x400EC7: main (in /code/minishell)
_______________________________________________________________________________________

the libft has some extra functions for two dimensional arrays:
-> ft_free2: it frees a split
-> ft_print2: it prints the split -debug
-> ft_splitdup: ft_strdups the whole split
-> ft_splitlen: returns the length of the split

and for env 
-> check_existence will check a split and search for a name until '\0' or '='
	to work with env
