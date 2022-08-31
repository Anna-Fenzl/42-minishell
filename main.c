/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/31 13:06:21 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_global	g_global;

void	minishell(void)
{
	while (1)
	{
		handle_signals();
		g_global.lexer = ft_lstnew(NULL);
		if (isatty(0))
			g_global.buf = readline("minishell> ");
		else
			g_global.buf = get_next_line(0);
		signal(SIGINT, SIG_IGN);
		if (g_global.buf == NULL)
			exit(g_global.error_code);
		handle_history(g_global.buf);
		if (!parse(g_global.buf, &g_global.lexer))
		{
			if (transform(g_global.lexer) == 0)
				execute();
			unlink(".ms_tmp");
			free_child(g_global.child);
		}
		else
			g_global.error_code = 258;
		handle_free(g_global.buf, g_global.lexer);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
		return (1);
	g_global.error_code = 0;
	set_default_env(env);
	minishell();
	return (0);
}
