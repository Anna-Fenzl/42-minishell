/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:12:19 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:31:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	get_cmd_num(char **cmds)
{
	int	i;

	i = 0;
	while (cmds != NULL && cmds[i] != NULL)
		i++;
	return (i);
}

void	create_child(t_child *child)
{
	int	i;
	int	cmd_num;

	i = 0;
	cmd_num = get_cmd_num(child->cmd);
	while ()
}

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
	dup2 (tmpout, 0);
	close(tmpin);
	close(tmpout);
}
