/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 20:14:58 by afenzl           ###   ########.fr       */
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
		buf = readline ("minishell.6.9> ");
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
		return (0);
	global.env = ft_splitdup(env);
	set_default_env(&global);
	minishell(&global);
	return (0);
}
