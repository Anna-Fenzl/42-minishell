/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 19:41:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_global;

// if (!parse(g_global.buf, &lexer))
// 	g_global.error_code = 258;
// print_lexer(lexer);
// handle_free(g_global.buf, lexer);
void	minishell(void)
{
	t_list	*lexer;

	while (1)
	{
		handle_signals();
		lexer = ft_lstnew(NULL);
		if (isatty(0))
			g_global.buf = readline("minishell> ");
		else
			g_global.buf = get_next_line(0);
		if (g_global.buf == NULL)
			exit(0);
		handle_history(g_global.buf);
		if (parse(g_global.buf, &lexer))
		{
			// print_lexer(lexer);
			if (transform(lexer) == 0)
				execute();
		}
		handle_free(g_global.buf, lexer);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	g_global.error_code = 0;
	if (argc != 1)
		return (1);
	set_default_env(env);
	minishell();
	return (0);
}
