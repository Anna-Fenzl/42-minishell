/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:35:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 18:27:20 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_waiting(void)
{
	int	ret_from_child;

	while (wait(&ret_from_child) != -1 || errno != ECHILD)
		continue ;
	if (WIFEXITED(ret_from_child))
		g_global.error_code = WEXITSTATUS(ret_from_child);
	printf("error code is %d\n", g_global.error_code);
}

void	redir_and_exec(int tmpin, int tmpout, int i, int *fd)
{
	char	*path;

	redir_infile(i, tmpin, fd);
	redir_outfile(i, tmpout, fd);
	exit_builtin(i);
	path = ft_get_path(g_global.child[i].cmd[0]);
	execve(path, g_global.child[i].cmd, g_global.env);
	ft_putstr_fd("minishell: failed: command not found\n", 2);
	exit(1);
}

// fork error return needs to be passed somehow
void	handle_multiple_cmd(int *tmpin, int *tmpout, int i, int *fd)
{
	int	id;

	*tmpout = fd[1];
	if (i == g_global.children_num - 1)
		close(fd[0]);
	id = fork();
	if (id < 0)
	{
		printf("could not fork\n");
		return ;
	}
	if (id == 0)
	{
		close(fd[0]);
		redir_and_exec(*tmpin, *tmpout, i, fd);
	}
	close(fd[1]);
	if (i > 0)
		close(*tmpin);
	*tmpin = fd[0];
}

// -->in child: is this neccessary??
// if (g_global.child[i].cmd == NULL)
// 	exit(0);
int	execute(void)
{
	int		tmpin;
	int		tmpout;
	int		fd[2];
	int		i;
	int		ret;

	i = 0;
	tmpin = dup(STDIN_FILENO);
	tmpout = dup(STDOUT_FILENO);
	if (g_global.children_num == 1)
	{
		ret = exec_builtin(g_global.child[i].cmd);
		if (ret != -1)
			return (ret);
	}
	while (i < g_global.children_num)
	{
		if (pipe(fd) == -1)
		{
			printf("could not pipe\n");
			return (1);
		}
		handle_multiple_cmd(&tmpin, &tmpout, i, fd);
		i++;
	}
	handle_waiting();
	close(tmpin);
	close(tmpout);
	return (0);
}
