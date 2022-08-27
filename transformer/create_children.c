/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:21:43 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 14:23:48 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	trunc_or_append(int *fd, int this_pipe, char *outfile)
{
	if (g_global.child[this_pipe].append == 1)
	{
		*fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	else
		*fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

int	handle_outfile(t_list *cur, int this_pipe)
{
	int	fd;

	if (((t_elem *)cur->content)->type == T_REDIR3
		|| ((t_elem *)cur->content)->type == T_REDIR1)
	{
		cur = cur->next;
		trunc_or_append(&fd, this_pipe, ((t_elem *)cur->content)->str);
		if (fd < 0)
		{
			ft_printf_fd(2, "minishell: %s: Permission denied\n",
				((t_elem *)cur->content)->str);
			return (1);
		}
		close(fd);
		if (g_global.child[this_pipe].outfile != NULL)
			free(g_global.child[this_pipe].outfile);
		g_global.child[this_pipe].outfile = ft_strdup
			(((t_elem *)cur->content)->str);
	}
	return (0);
}

int	handle_cmds(t_list *cur, int this_pipe)
{
	if (((t_elem *)cur->content)->type == T_CMD
		|| ((t_elem *)cur->content)->type == T_ARGS
		|| ((t_elem *)cur->content)->type == T_OPT)
	{
		g_global.child[this_pipe].cmd = ft_splitjoin
			(g_global.child[this_pipe].cmd, ((t_elem *)cur->content)->str);
	}
	return (0);
}

/*
	1. REDIR IN 
		- REDIR 4 --> << here_dock
		(reads from terminal and writes to tmp)
		- REDIR 2 --> <
		(checks if file exists and has permisions)
		(infile --> char *infile)
	2. REDIR OUT
		- REDIR3 --> >> append
		- REDIR1 --> > trunc
		(opens all the files accordingly)
*/
int	handle_redirs(t_list *cur, int this_pipe)
{
	if (((t_elem *)cur->content)->type == T_REDIR4)
	{
		if (handle_here_dock(cur, this_pipe) == 1)
			return (1);
	}
	else if (((t_elem *)cur->content)->type == T_REDIR2)
	{
		if (handle_infile(cur, this_pipe) == 1)
			return (1);
	}
	else if (((t_elem *)cur->content)->type == T_REDIR3)
		g_global.child[this_pipe].append = 1;
	else if (((t_elem *)cur->content)->type == T_REDIR1)
		g_global.child[this_pipe].append = 0;
	return (0);
}

/*
	ERRORCODES NOT SET !!
	just return 1 on error

	goes trough the tokenised parsing list and assigns it to child[i]
	1. t_CMD && T_ARGS --> char **cmds
	2. REDIR
*/
int	create_children(t_list **lexer)
{
	t_list	*cur;
	int		this_pipe;

	cur = *lexer;
	while (cur && ((t_elem *)cur->content))
	{
		this_pipe = ((t_elem *)cur->content)->this_pipe;
		handle_cmds(cur, this_pipe);
		if (handle_redirs(cur, this_pipe) == 1
			|| handle_outfile(cur, this_pipe) == 1)
			return (1);
		cur = cur->next;
	}
	return (0);
}
