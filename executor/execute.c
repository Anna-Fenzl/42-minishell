/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:35:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/24 22:06:02 by afenzl           ###   ########.fr       */
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

/*
	NOT IN INTERACTIVE mode
	Ctrl -C (SIGINT) should stop the child (SIGTERM) i guess
	Ctrl -\ (SIGQUIT) should default
	Ctrl -D 
*/
void	set_signals(void)
{
	signal(SIGQUIT, SIG_DFL);
}

int	handle_pipes(int *tmpin, int *tmpout, int i, int *fd)
{
	int	id;

	*tmpout = fd[1];
	if (i == g_global.children_num - 1)
		close(fd[0]);
	id = fork();
	if (id < 0)
	{
		printf("Error: could not fork\n");
		return (1);
	}
	if (id == 0)
	{
		set_signals();
		close(fd[0]);
		redir_and_exec(*tmpin, *tmpout, i, fd);
	}
	close(fd[1]);
	if (i > 0)
		close(*tmpin);
	*tmpin = fd[0];
	return (0);
}

int	handle_subshells(int tmpin, int tmpout)
{
	int	i;
	int	fd[2];

	i = 0;
	while (i < g_global.children_num)
	{
		if (pipe(fd) == -1)
		{
			printf("Error: could not pipe\n");
			return (1);
		}
		if (handle_pipes(&tmpin, &tmpout, i, fd) == 1)
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
	int	tmpin;
	int	tmpout;
	int	ret;

	tmpin = dup(STDIN_FILENO);
	tmpout = dup(STDOUT_FILENO);
	if (g_global.children_num == 1)
	{
		ret = handle_single_builtin(tmpout);
		if (ret != -1)
			return (ret);
	}
	ret = handle_subshells(tmpin, tmpout);
	handle_waiting();
	close(tmpin);
	close(tmpout);
	return (ret);
}
