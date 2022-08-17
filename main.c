/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/17 16:55:33 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// man 7 environ --> info about env enviroment

// to enter tabs into bash ctrl V t
void	minishell(t_global *global)
{
	char	*buf;

	while (1)
	{
		ft_print2(global->env);
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

	// if env is unset set the right variables yourself
int	main(int argc, char **argv, char **env)
{
	t_global	global;

	(void)argv;
	if (argc != 1)
		return (0);
	global.env = ft_splitdup(env);
	minishell(&global);
	return (0);
}
