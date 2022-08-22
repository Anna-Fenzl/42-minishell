/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 20:56:06 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_global;

// ft_split_new is missing --> var_expansion is fucked
		// if (!parse(g_global.buf, &lexer))
		// 	g_global.error_code = 258;
		// print_lexer(lexer);
		// handle_free(g_global.buf, lexer);
void	minishell(void)
{
	t_list	*lexer;

	int i = 0;
	while (1)
	{
		// handle_signals();
		lexer = ft_lstnew(NULL);
		g_global.buf = readline("minishell> ");
		// if (i == 1)
		// 	sleep(100);
		if (g_global.buf == NULL)
			exit(0);
		handle_history(g_global.buf);
		if (parse(g_global.buf, &lexer))
		{
			print_lexer(lexer);
			transform(lexer);
			execute();
		}
		handle_free(g_global.buf, lexer);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	g_global.error_code = 0;
	if (argc != 1)
		return (1);
	set_default_env(env);
	builtin_env(g_global.env);
	minishell();
	return (0);
}
