/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:47:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/25 11:38:36 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	checks if cmd is a builtin and executes it
	returns -1 if cmd is NOT a builtin;
	else it returns the return value of the builtin
	(either 0 or 1)
*/
int	exec_builtin(char **cmd)
{
	int	len;

	if (cmd == NULL || cmd[0] == NULL)
		return (-1);
	len = ft_strlen(cmd[0]);
	if (ft_strncmp(cmd[0], "cd", len) == 0)
		return (builtin_cd(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "echo", len) == 0)
		return (builtin_echo(cmd));
	else if (ft_strncmp(cmd[0], "env", len) == 0)
		return (builtin_env());
	else if (ft_strncmp(cmd[0], "exit", len) == 0)
		return (builtin_exit(cmd));
	else if (ft_strncmp(cmd[0], "export", len) == 0)
		return (builtin_export(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "unset", len) == 0)
		return (builtin_unset(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "pwd", len) == 0)
		return (builtin_pwd());
	return (-1);
}

/*
	wrapper for builtins since they need to exit
	in the children
*/
void	exit_builtin(int i)
{
	int	ret;

	ret = exec_builtin(g_global.child[i].cmd);
	if (ret != -1)
		exit (ret);
}

/*
	returns 1 if builtin is found and 0 if not
*/
int	check_if_builtin(char **cmd)
{
	int	len;

	if (cmd == NULL || cmd[0] == NULL)
		return (0);
	len = ft_strlen(cmd[0]);
	if (ft_strncmp(cmd[0], "cd", len) == 0
		|| ft_strncmp(cmd[0], "echo", len) == 0
		|| ft_strncmp(cmd[0], "env", len) == 0
		|| ft_strncmp(cmd[0], "exit", len) == 0
		|| ft_strncmp(cmd[0], "export", len) == 0
		|| ft_strncmp(cmd[0], "unset", len) == 0
		|| ft_strncmp(cmd[0], "pwd", len) == 0)
		return (1);
	return (0);
}

/*
	executes builtin in parent in case 
*/
int	handle_single_builtin(int tmpout)
{
	int	fd;
	int	ret;

	if (check_if_builtin(g_global.child[0].cmd) == 1)
	{
		if (g_global.child[0].outfile != NULL)
		{
			trunc_or_append(&fd, 0, g_global.child[0].outfile);
			if (fd < 0)
			{
				printf("Error: could not write to outfile\n");
				return (1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		ret = exec_builtin(g_global.child[0].cmd);
		if (g_global.child[0].outfile != NULL)
			dup2(tmpout, STDOUT_FILENO);
		return (ret);
	}
	return (-1);
}
