/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:03 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/26 21:30:58 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_flag(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL && args[i][0] == '-')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] == '\0')
			i++;
		else
			return (i + 1);
	}
	return (i + 1);
}

int	builtin_echo(char **cmd)
{
	int	printindex;
	int	flag;

	flag = 1;
	printindex = check_flag(&(cmd[1]));
	if (printindex == 1)
		flag = 0;
	while (cmd[printindex] != NULL)
	{
		ft_printf("%s", cmd[printindex]);
		if (cmd[printindex + 1] != NULL)
			ft_printf(" ");
		printindex++;
	}
	if (flag == 0)
		ft_printf("\n");
	return (EXIT_SUCCESS);
}
