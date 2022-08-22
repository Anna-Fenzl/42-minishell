/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:21:43 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 19:00:37 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	debug_print_children(void)
{
	int	i;

	i = 0;
	while (i < g_global.children_num)
	{
		printf("\nIN CHILD NUMBER %i\n___________________________________\n", i);
		printf("\t-->CMD\n");
		ft_print2(g_global.child[i].cmd);
		printf("\t-->REDIR_OUT(append) = %i\n", g_global.child[i].append);
		printf("\t-->INFILE = %s\n", g_global.child[i].infile);
		printf("\t-->OUTFILE = %s\n", g_global.child[i].outfile);
		printf("__________________________________\n");
		i++;
	}
}

/*
	NEEDS TO EXPAND THE VARIABLES
	--> make delim to t_elem and check if quotes
	- if yes --> dont expand them

	reads from terminal until delimiter is reached
	and writes it into tmp file called .ms_tmp
*/
int	handle_here_dock(t_list *cur, int this_pipe)
{
	int		fd;
	char	*delim;
	char	*input;

	cur = cur->next;
	delim = ft_strjoin(((t_elem *)cur->content)->str, "\n");
	fd = open(".ms_tmp", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (1);
	write(1, "here_doc> ", 10);
	input = get_next_line(STDIN_FILENO);
	while (input != NULL && ft_strncmp(input, delim, ft_strlen(input) + 1) != 0)
	{
		//expand or not the variables HERE PLEASE (I THINK SO AT LEAST)
		ft_putstr_fd(input, fd);
		free(input);
		write(1, "here_doc> ", 10);
		input = get_next_line(STDIN_FILENO);
		printf("input  = |%s|\n", input);
	}
	free(input);
	g_global.child[this_pipe].infile = ft_strdup(".ms_tmp");
	return (0);
}

int	handle_infile(t_list *cur, int this_pipe)
{
	int	fd;

	cur = cur->next;
	fd = open(((t_elem *)cur->content)->str, O_RDONLY);
	if (fd < 0)
	{
		if (access(((t_elem *)cur->content)->str, F_OK) < 0)
			printf("minishell: %s: No such file or directory\n",
				((t_elem *)cur->content)->str);
		else
			printf("minishell: %s: Permission denied\n",
				((t_elem *)cur->content)->str);
		return (1);
	}
	close(fd);
	g_global.child[this_pipe].infile = ft_strdup(((t_elem *)cur->content)->str);
	return (0);
}

int	open_outfiles(char *outfile, int this_pipe)
{
	int	fd;

	if (g_global.child[this_pipe].append == 1)
		fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (fd);
}

int	handle_outfile(t_list *cur, int this_pipe)
{
	int	fd;

	if (((t_elem *)cur->content)->type == T_REDIR3
		|| ((t_elem *)cur->content)->type == T_REDIR1)
	{
		cur = cur->next;
		fd = open_outfiles(((t_elem *)cur->content)->str, this_pipe);
		if (fd < 0)
		{
			printf("minishell: %s: Permission denied\n",
				((t_elem *)cur->content)->str);
			return (1);
		}
		close(fd);
		g_global.child[this_pipe].outfile = ft_strdup
			(((t_elem *)cur->content)->str);
	}
	return (0);
}

int	handle_cmds(t_list *cur, int this_pipe)
{
	if (((t_elem *)cur->content)->type == T_CMD
		|| ((t_elem *)cur->content)->type == T_ARGS)
	{
		g_global.child[this_pipe].cmd = ft_splitjoin
			(g_global.child[this_pipe].cmd, ((t_elem *)cur->content)->str);
	}
	return (0);
}

/*
	goes trough the tokenised parsing list and assigns it to child[i]
	1. t_CMD && T_ARGS --> char **cmds
	2. REDIR IN 
		- REDIR 4 --> << here_dock
		(reads from terminal and writes to tmp)
		- REDIR 2 --> <
		(checks if file exists and has permisions)
		(infile --> char *infile)
	3. REDIR OUT
		- REDIR3 --> >> append
		- REDIR1 --> > trunc
		(opens all the files accordingly)
*/
int	go_trough_lexer(t_list **lexer)
{
	t_list	*cur;
	int		this_pipe;

	cur = *lexer;
	while (cur && ((t_elem *)cur->content))
	{
		this_pipe = ((t_elem *)cur->content)->this_pipe;
		handle_cmds(cur, this_pipe);
		if (((t_elem *)cur->content)->type == T_REDIR4)
			handle_here_dock(cur, this_pipe);
		else if (((t_elem *)cur->content)->type == T_REDIR2)
			handle_infile(cur, this_pipe);
		else if (((t_elem *)cur->content)->type == T_REDIR3)
			g_global.child[this_pipe].append = 1;
		else if (((t_elem *)cur->content)->type == T_REDIR1)
			g_global.child[this_pipe].append = 0;
		handle_outfile(cur, this_pipe);
		cur = cur->next;
	}
	debug_print_children();
	return (0);
}
