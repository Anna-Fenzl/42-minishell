/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:47:01 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 18:57:56 by afenzl           ###   ########.fr       */
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
	if (cmd == NULL || cmd[0] == NULL)
		return (-1);
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
		return (builtin_cd(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "echo", 5) == 0)
		return (builtin_echo(cmd));
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		return (builtin_env());
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		return (builtin_exit(cmd));
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (builtin_export(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (builtin_unset(&g_global.env, cmd));
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
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
	if (cmd == NULL || cmd[0] == NULL)
		return (0);
	if (ft_strncmp(cmd[0], "cd", 3) == 0
		|| ft_strncmp(cmd[0], "echo", 5) == 0
		|| ft_strncmp(cmd[0], "env", 4) == 0
		|| ft_strncmp(cmd[0], "exit", 5) == 0
		|| ft_strncmp(cmd[0], "export", 7) == 0
		|| ft_strncmp(cmd[0], "unset", 6) == 0
		|| ft_strncmp(cmd[0], "pwd", 4) == 0)
		return (1);
	return (0);
}

/*
	executes builtin in parent
	if found returns exitcode of builtin 
	if not returns -1
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
				ft_printf_fd(2, "minishell: `%s': Permission denied\n",
					g_global.child[0].outfile);
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
