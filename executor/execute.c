/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:35:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 16:57:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	waits for the children to terminate
	and sets last exit to the exitstatus
*/
void	handle_waiting(void)
{
	int	ret_from_child;

	while (wait(&ret_from_child) != -1 || errno != ECHILD)
	{
		if (WIFEXITED(ret_from_child))
			g_global.error_code = WEXITSTATUS(ret_from_child);
	}
}

void	redir_and_exec(int *fd, int *fd_prev, int i)
{
	char	*path;

	redir_infile(i, fd, fd_prev);
	redir_outfile(i, fd, fd_prev);
	exit_builtin(i);
	if (g_global.child[i].cmd[0] == NULL)
		path = NULL;
	else
		path = ft_get_path(g_global.child[i].cmd[0]);
	execve(path, g_global.child[i].cmd, g_global.env);
	ft_printf_fd(2, "minishell: %s: command not found\n",
		g_global.child[i].cmd[0]);
	exit(127);
}

int	handle_pipes(int *fd, int *fd_prev, int i)
{
	int	id;

	id = fork();
	if (id < 0)
	{
		ft_putstr_fd("Error: could not fork\n", 2);
		return (1);
	}
	if (id == 0)
	{
		set_signals();
		redir_and_exec(fd, fd_prev, i);
	}
	if (i == g_global.children_num - 1 || i != 0)
		fd_close(fd_prev);
	assign_prev(fd, fd_prev);
	fd_close(fd);
	return (0);
}

int	handle_subshells(int *fd, int *fd_prev)
{
	int	i;

	i = 0;
	while (i < g_global.children_num)
	{
		if (i < g_global.children_num - 1)
		{
			if (pipe(fd) == -1)
			{
				ft_putstr_fd("Error: could not pipe\n", 2);
				return (1);
			}
		}
		if (handle_pipes(fd, fd_prev, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

/*
	in case there only a single builtin
	its gonna execute that one in the parent
	else its gonna create subshells
*/
int	execute(void)
{
	int	fd[2];
	int	fd_prev[2];
	int	ret;

	if (g_global.children_num == 1)
	{
		fd[1] = dup(STDOUT_FILENO);
		ret = handle_single_builtin(fd[1]);
		if (ret != -1)
		{
			g_global.error_code = ret;
			close(fd[1]);
			return (ret);
		}
	}
	ret = handle_subshells(fd, fd_prev);
	handle_waiting();
	return (ret);
}
