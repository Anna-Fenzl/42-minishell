/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:59:52 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 17:45:59 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// man 7 environ --> info about env enviroment
// if SHLVL not found or not a number its set to 1 on default

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
	if (check_existence(global->env, "_=") < 0)// its ./minishell in the env rn --> should do it on default? (yeet)
		builtin_export(&global->env, "_=/usr/bin/env");
	if (check_existence(global->env, "SHLVL=") < 0)
		builtin_export(&global->env, "SHLVL=1");
	else
		handle_shlvl(global->env);
}

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
	printf("-------------------------------------\n");
	ft_print2(global.env);
	builtin_unset(&global.env, "SHLVL");
	builtin_export(&global.env, "SHLVL=kdfh");
	printf("-------------------------------------\n");
	builtin_env(global.env);
	set_default_env(&global);
	printf("-------------------------------------\n");
	builtin_env(global.env);
	// system("leaks minishell");
	// minishell(&global);
	return (0);
}
