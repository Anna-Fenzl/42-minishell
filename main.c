/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 17:15:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// to enter tabs into bash ctrl V t
void	minishell(void)
{
	char	*buf;

	while (1)
	{
		buf = readline ("minishell.6.9> ");
		if (ft_strcmp(buf, "exit") == 0)
		{
			free(buf);
			printf("exit\n");
			return ;
		}
		add_history(buf);
		free(buf);
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (0);
	minishell();
	return (0);
}
