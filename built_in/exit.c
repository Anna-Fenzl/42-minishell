/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 21:21:29 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_error(char *str)
{
	printf("minishell: exit: %s numeric argument required\n", str);
	exit (255);
}

static long	ft_numcpy(int i, long res, char *p, char *str)
{
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			res = res * 10 + p[i] - '0';
			i++;
			if (i > 19 && res > LLONG_MAX)
				ft_error(str);
		}
		else
			ft_error(str);
	}
	return (res);
}

long long	atoll_check(char *str)
{
	int			i;
	long long	res;
	int			n;
	char		*p;

	i = 0;
	res = 0;
	n = 1;
	p = (char *)str;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i + 1] == '\0')
			ft_error(str);
		if (p[i] == '-')
			n = -1;
		i++;
	}
	res = ft_numcpy(i, res, p, str);
	if (res > LLONG_MAX)
		ft_error(str);
	return (res * n);
}

/*
	need to free before exiting!!!
*/
int	builtin_exit(char **arg)
{
	long	exitcode;

	printf("exit\n");
	if (arg[1] != NULL)
		exitcode = atoll_check(arg[1]);
	if (ft_splitlen(arg) > 2)
	{
		printf("minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	exit(exitcode % 256);
}
