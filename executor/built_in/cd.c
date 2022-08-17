/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:00 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/17 16:56:06 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if cd is without any arguments it leads to HOME=
// -(if thats not in env it prints an error)
// ==> DONE

// enetering bash there is no OLDPWD yet -- minishell does have it
// 
// if they are in environ but not show in env (=) they will get a value
// ==> DONE
// 
// PWD is there on default, OLDPWD after the first cd
// if unset, the dont reapear
// ---> but after PWD is unset for the first time + cd --> OLDPWD='empty'
// ---> second time its normal again --> OLDPWD='old/pwd/'
// 
// rn OLDPWD will apear after cd no matter what.
// if pwd is not found OLDPWD is empty
// 
// 
// shouldnt segfault in case 
// -mkdir test
// -cd test
// -rm -rf ../test
// -pwd
// 
// 

void	add_old_pwd(char ***env, int line)
{
	char	*tmp;

	if (line >= 0)
	{
		tmp = ft_strjoin("OLDPWD=", &(*env)[line][3]);
		builtin_export(env, tmp);
		free(tmp);
	}
	else
		builtin_export(env, "OLDPWD=");
}

void	set_old_pwd(char ***env, int line)
{
	int		i;

	i = 0;
	while (*env && (*env)[i] != NULL)
	{
		if (ft_strncmp("OLDPWD", (*env)[i], 6) == 0)
		{
			free((*env)[i]);
			if (line < 0)
			{
				(*env)[i] = ft_strdup("OLDPWD=");
				return ;
			}
			(*env)[i] = ft_strjoin("OLDPWD", &(*env)[line][3]);
			return ;
		}
		i++;
	}
	add_old_pwd(env, line);
}

void	change_pwd(char ***env)
{
	int		i;
	char	pwd[PATH_MAX];

	i = 0;
	getcwd(pwd, PATH_MAX);
	while (*env && (*env)[i] != NULL)
	{
		if (ft_strncmp("PWD", (*env)[i], 3) == 0)
		{
			set_old_pwd(env, i);
			free((*env)[i]);
			(*env)[i] = ft_strjoin("PWD=", pwd);
			return ;
		}
		i++;
	}
	set_old_pwd(env, -1);
}

void	to_home_dir(char ***env)
{
	int	i;

	i = 0;
	while (*env && (*env)[i] != NULL)
	{
		if (ft_strncmp("HOME=", (*env)[i], 5) == 0)
		{
			chdir(&(*env)[i][5]);
			change_pwd(env);
			return ;
		}
		i++;
	}
	printf("minishell: cd: HOME not set\n");
}

// dont need to handle macros
int	builtin_cd(char ***env, char *path)
{
	if (path == NULL)
		to_home_dir(env);
	else
	{
		if (chdir(path) < 0)
		{
			printf("minishell: cd: No such file or directory");
			return (1);
		}
		change_pwd(env);
	}
	return (0);
}
