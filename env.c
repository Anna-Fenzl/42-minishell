/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:23:39 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 20:20:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

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
	if (lvl == 0 || lvl >= 1000)
	{
		if (lvl >= 1000)
			printf("minishell: warning: shell level (%i)to high"
				", resetting to 1\n", lvl);
		builtin_export(&env, "SHLVL=1");
	}
	else
	{
		num = ft_itoa(lvl + 1);
		var = ft_strjoin("SHLVL=", num);
		builtin_export(&env, var);
		free(var);
		free(num);
	}
}

/*
	sets PWD, SHLVL and _=(aka last executed pogramm) to default
	_= still could be implemented
*/
void	set_default_env(t_global *global)
{
	char	pwd[PATH_MAX];
	char	*tmp;

	builtin_unset(&global->env, "PWD");
	if (getcwd(pwd, PATH_MAX))
	{
		tmp = ft_strjoin("PWD=", pwd);
		builtin_export(&global->env, tmp);
		free(tmp);
	}
	builtin_export(&global->env, "_=/usr/bin/env");
	if (check_existence(global->env, "SHLVL=") < 0)
		builtin_export(&global->env, "SHLVL=1");
	else
		handle_shlvl(global->env);
}
