/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:08 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 19:18:14 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_error(char *str)
{
	ft_printf_fd(2, "minishell: exit: %s: numeric argument required\n", str);
	handle_free(g_global.buf, g_global.lexer);
	free_child(g_global.child);
	exit (255);
}

static long long	ft_numcpy(int i, long long res, char *p, char *str)
{
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			res = res * 10 + p[i] - '0';
			i++;
			if (res < 0)
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
	if (p[0] == '\0')
		ft_error(p);
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i + 1] == '\0')
			ft_error(str);
		if (p[i] == '-')
			n = -1;
		i++;
	}
	res = ft_numcpy(i, res, p, str);
	return (res * n);
}

/*
	need to free before exiting!!!
*/
int	builtin_exit(char **arg)
{
	long	exitcode;

	exitcode = g_global.error_code;
	ft_putstr_fd("exit\n", 0);
	if (arg[1] != NULL)
		exitcode = atoll_check(arg[1]);
	if (ft_splitlen(arg) > 2)
	{
		ft_printf_fd(2, "minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	handle_free(g_global.buf, g_global.lexer);
	free_child(g_global.child);
	exit(exitcode % 256);
}

// with 0
// 412:STD_OUT: 29  STD_ERR: 3  EXIT_CODE: 1
// with 1
// 412:STD_OUT: 74  STD_ERR: 3  EXIT_CODE: 1 
// with 2
// 412:STD_OUT: 29  STD_ERR: 17  EXIT_CODE: 1 