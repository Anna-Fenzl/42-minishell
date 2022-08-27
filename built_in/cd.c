/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:00 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 14:28:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
// shouldnt segfault in case 
// -mkdir test
// -cd test
// -rm -rf ../test
// -pwd
// 

void	set_old_pwd(char ***env, int line)
{
	char	*tmp;
	int		old_pwd;

	old_pwd = check_existence(*env, "OLDPWD");
	if (old_pwd >= 0)
	{
		free((*env)[old_pwd]);
		if (line < 0)
		{
			(*env)[old_pwd] = ft_strdup("OLDPWD=");
			return ;
		}
		(*env)[old_pwd] = ft_strjoin("OLDPWD", &(*env)[line][3]);
	}
	if (line >= 0)
	{
		tmp = ft_strjoin("OLDPWD=", &(*env)[line][3]);
		handle_export(env, tmp);
		free(tmp);
	}
	else
		handle_export(env, "OLDPWD=");
}

void	change_pwd(char ***env)
{
	int		line;
	char	pwd[PATH_MAX];

	line = check_existence(*env, "PWD");
	getcwd(pwd, PATH_MAX);
	if (line >= 0)
	{
		set_old_pwd(env, line);
		free((*env)[line]);
		(*env)[line] = ft_strjoin("PWD=", pwd);
	}
	else
		set_old_pwd(env, -1);
}

int	to_home_dir(char ***env)
{
	int	line;

	line = check_existence(*env, "HOME=");
	if (line >= 0)
	{
		chdir(&(*env)[line][5]);
		change_pwd(env);
	}
	else
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	return (0);
}

/*
	dont need to handle macros
	no arguments --> to HOME
	can take more than one arg, only gonna check the first one
*/
int	builtin_cd(char ***env, char **path)
{
	if (path == NULL)
		return (1);
	if (path[1] == NULL)
	{
		if (to_home_dir(env) == 1)
			return (EXIT_FAILURE);
	}
	else
	{
		if (chdir(path[1]) < 0)
		{
			ft_printf_fd(2, "minishell: cd: %s: No such file or directory\n",
				path[1]);
			return (EXIT_FAILURE);
		}
		change_pwd(env);
	}
	return (EXIT_SUCCESS);
}
