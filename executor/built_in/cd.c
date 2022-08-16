/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:00 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 21:08:24 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if no argument given cd leads to HOME directory wich is in enviroment
// absolute path;
// relative path;

void	change_pwd(char ***env)
{
	int		i;
	char	pwd[PATH_MAX];

	i = 0;
	getcwd(pwd, PATH_MAX);
	printf("pwd is |%s|\n", pwd);
	while (*env && (*env)[i] != NULL)
	{
		if (ft_strncmp("PWD=", (*env)[i], 4) == 0)
		{
			printf("it found PWD in line %i\n", i);
			free((*env)[i]);
			(*env)[i] = ft_strjoin("PWD=", pwd);
			return ;
		}
		i++;
	}
	builtin_export(env, ft_strjoin("PWD=", pwd));
}

void	to_home_dir(char **env)
{
	int	i;

	i = 0;
	while (env && env[i] != NULL)
	{
		if (ft_strncmp("HOME=", env[i], 5) == 0)
		{
			chdir(&env[i][5]);
			change_pwd(&env);
			return ;
		}
		i++;
	}
	printf("minishell: cd: HOME not set\n");
}

int	builtin_cd(char **env, char *path)
{
	if (path == NULL)
		to_home_dir(env);
	return (0);
}
