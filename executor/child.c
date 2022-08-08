/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:12:19 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/08 13:20:56 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	create_childs(t_child *child, int tmpout)
{
	int		i;
	int		id;
	int		cmd_num;
	int		fd_pipe[2];
	// char	path;

	i = 0;
	cmd_num = ft_splitlen(child->cmd);
	while (i < cmd_num)
	{
		dup2(child->fd[0], 0);
		close(child->fd[0]);
		if (i == cmd_num -1)
		{
			if (child->outfile != NULL)
			{
				if (child->mode == trunc)
					child->fd[1] = open(child->outfile, O_CREAT | O_WRONLY,
							O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				else if (child->mode == append)
					child->fd[1] = open(child->outfile, O_CREAT | O_WRONLY,
							O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			}
			else
				child->fd[1] = tmpout;
			if (child->fd[1] < 0)
				perror("could not open outfile\n");
		}
		else
		{
			pipe(fd_pipe);
			child->fd[1] = fd_pipe[1];
			child->fd[0] = fd_pipe[0];
		}
		dup2(child->fd[1], 1);
		close(child->fd[1]);
		id = fork();
		if (id < 0)
			perror("could not fork\n");
		if (id == 0)
		{
			perror("hi from child");
			path = ft_get_path(NULL, child->cmd[i]);
			execve(path, child->flags[i], NULL);
			perror("could not execute\n");
		}
		i++;
	}
}

// have the parent prozess do all the piping redirection before forking
/**
 * 1. safe in & out
 * 2. set the initial input
 * --> if infile exists infile,
 * -->if not read from terminal
 * 3. while loop
 * 4. close the rest
 */
void	exec_in_child(t_child *child)
{
	int	tmpin;
	int	tmpout;

	tmpin = dup(0);
	tmpout = dup(1);
	if (child->infile != NULL)
	{
		child->fd[0] = open(child->infile, O_RDONLY);
		if (child->fd[0] < 0)
		{
			perror ("could not read from infile");
			return ;
		}
	}	
	else
		child->fd[0] = tmpin;
	create_childs(child, tmpout);
	dup2 (tmpin, 0);
	dup2 (tmpout, 1);
	close(tmpin);
	close(tmpout);
}

int	main(void)
{
	t_child	child;
	int		i;

	i = 0;
	child.cmd = ft_split("/bin/cat /bin/cat /bin/cat", ' ');
	while (i < ft_splitlen(child.cmd))
	{
		child.flags[i] = ft_split("cat -e", ' ');
		i++;
	}
	child.infile = NULL;
	child.outfile = "outfile";
	child.mode = trunc;
	exec_in_child(&child);
	return (0);
}
