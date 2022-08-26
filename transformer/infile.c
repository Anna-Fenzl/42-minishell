/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:11:48 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/26 14:47:56 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	NEEDS TO EXPAND THE VARIABLES!!!
	//expand or not the variables at start of while loop (I THINK SO AT LEAST)
	
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
	fd = open(".ms_tmp", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (1);
	write(1, "here_doc> ", 10);
	delim = ft_strjoin(((t_elem *)cur->content)->str, "\n");
	input = get_next_line(STDIN_FILENO);
	while (input != NULL && ft_strncmp(input, delim, ft_strlen(input) + 1) != 0)
	{
		ft_putstr_fd(input, fd);
		free(input);
		write(1, "here_doc> ", 10);
		input = get_next_line(STDIN_FILENO);
	}
	free(input);
	free(delim);
	if (g_global.child[this_pipe].infile != NULL)
		free(g_global.child[this_pipe].infile);
	g_global.child[this_pipe].infile = ft_strdup(".ms_tmp");
	return (0);
}

/*
	checks infile and sets it in child
*/
int	handle_infile(t_list *cur, int this_pipe)
{
	// int	fd;

	cur = cur->next;
	// fd = open(((t_elem *)cur->content)->str, O_RDONLY);
	// if (fd < 0)
	// {
	// 	if (access(((t_elem *)cur->content)->str, F_OK) < 0)
	// 		ft_putstr_fd("minishell: No such file or directory\n", 2);
	// 	else
	// 		ft_putstr_fd("minishell: Permission denied\n", 2);
	// 	g_global.error_code = 1;
	// 	return (1);
	// }
	// close(fd);
	if (g_global.child[this_pipe].infile != NULL)
		free(g_global.child[this_pipe].infile);
	g_global.child[this_pipe].infile = ft_strdup(((t_elem *)cur->content)->str);
	return (0);
}
