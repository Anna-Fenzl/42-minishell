/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/19 14:55:58 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// to enter tabs into bash ctrl V t
void	minishell(t_global *global)
{
	char	*buf;

	while (1)
	{
		builtin_env(global->env);
		buf = readline ("minishell> ");
		if (ft_strcmp(buf, "exit") == 0)
		{
			free(buf);
			ft_printf("exit\n");
			return ;
		}
		add_history(buf);
		free(buf);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_global	global;

	(void)argv;
	if (argc != 1)
		return (1);
	set_default_env(&global, env);
	minishell(&global);
	return (0);
}
