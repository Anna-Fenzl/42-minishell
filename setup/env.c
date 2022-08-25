/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:23:39 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/25 14:55:40 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// man 7 environ --> info about env enviroment
char	*skip_until_value(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && str[i] != '=')
	i++;
	if (str[i] == '=')
		i++;
	return (&str[i]);
}

/*
	if SHLVL is over 1000 there is a warning printed out
	if SHLVL is negative the next time its 0
	if SHLVL is not valid its set to 1 on default
*/
int	shlvl_edgecases(char **env, int lvl)
{
	if (lvl == 0 || lvl >= 1000)
	{
		if (lvl >= 1000)
			ft_putstr_fd("minishell: warning: shell level (>1000)to high"
				", resetting to 1\n", 2);
		handle_export(&env, "SHLVL=1");
		return (1);
	}
	else if (lvl < 0)
	{
		handle_export(&env, "SHLVL=0");
		return (1);
	}
	return (0);
}

/*
	if SHLVL not found or not a number its set to 1 on default
	if SHLVL is valid it gets incremented by one
*/
void	handle_shlvl(char **env)
{
	int		line;
	int		lvl;
	char	*var;
	char	*num;

	line = check_existence(env, "SHLVL=");
	var = env[line];
	var = skip_until_value(var);
	lvl = ft_atoi(var);
	if (shlvl_edgecases(env, lvl) == 0)
	{
		num = ft_itoa(lvl + 1);
		var = ft_strjoin("SHLVL=", num);
		handle_export(&env, var);
		free(num);
		free(var);
	}
}

/*
	sets PWD, SHLVL and _=(aka last executed pogramm) to default
*/
void	set_default_env(char **env)
{
	char	pwd[PATH_MAX];
	char	*tmp;

	g_global.env = ft_splitdup(env);
	handle_unset(&g_global.env, "PWD");
	if (getcwd(pwd, PATH_MAX))
	{
		tmp = ft_strjoin("PWD=", pwd);
		handle_export(&g_global.env, tmp);
		free(tmp);
	}
	if (check_existence(g_global.env, "SHLVL=") < 0)
		handle_export(&g_global.env, "SHLVL=1");
	else
		handle_shlvl(g_global.env);
	handle_export(&g_global.env, "_=/usr/bin/env");
}
