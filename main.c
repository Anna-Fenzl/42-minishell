/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 13:41:19 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// to enter tabs into bash ctrl V t
void	minishell(t_global *global)
{
	while (1)
	{
		builtin_env(global->env);
		g_global.buf = readline ("minishell> ");
		if (g_global.buf == NULL)
			exit(0);
		if (ft_strcmp(g_global.buf, "exit") == 0)
		{
			free(g_global.buf);
			ft_printf("exit\n");
			return ;
		}
		add_history(g_global.buf);
		free(g_global.buf);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lexer;

	(void)argv;
	g_global.error_code = 0;
	if (argc != 1)
		return (1);
	set_default_env(&g_global, env); // in case we using global var there no need to pass it like option just call it in the function
	lexer = ft_lstnew(NULL);
	minishell(&g_global);
	if (!parser(g_global.buf, lexer))
		g_global.error_code = 127;
	return (0);
}
