/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:11:48 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 17:42:35 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*expand_if_exists(char	*var)
{
	char	*str;
	int		line;
	int		i;

	i = 0;
	line = check_existence(g_global.env, &var[1]);
	free(var);
	if (line != -1)
	{
		str = g_global.env[line];
		while (str != NULL && str[i] != '=' && str[i] != '\0')
			i++;
		if (str != NULL && str[i] == '=')
			i++;
		var = ft_strdup(&str[i]);
	}
	else
		var = ft_strdup("");
	return (var);
}

char	*expand_variables(char *input)
{
	char	**split;
	char	*tmp;
	int		i;

	i = 0;
	split = ft_new_split(input);
	free(input);
	input = ft_strdup("");
	while (split && split[i] != NULL)
	{
		if (split[i][0] == '$' && split[i][1] != '\0')
		{
			split[i] = expand_if_exists(split[i]);
		}
		tmp = input;
		input = ft_strjoin(tmp, split[i]);
		free(tmp);
		i++;
	}
	ft_free2(split);
	return (input);
}

static int	create_tmpfile(int *fd)
{
	*fd = open(".ms_tmp", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (*fd < 0)
		return (1);
	return (0);
}

/*
	reads from terminal until delimiter is reached
	and writes it into tmp file called .ms_tmp
	in case there are '$' it expands them
*/
int	handle_here_dock(t_list *cur, int this_pipe)
{
	char	*delim;
	char	*input;
	int		fd;

	cur = cur->next;
	if (create_tmpfile(&fd) == 1)
		return (1);
	write(1, "here_doc> ", 10);
	delim = ft_strjoin(((t_elem *)cur->content)->str, "\n");
	input = get_next_line(STDIN_FILENO);
	while (input != NULL && ft_strncmp(input, delim, ft_strlen(input) + 1) != 0)
	{
		if (((t_elem *)cur->content)->quotes == 0)
			input = expand_variables(input);
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
	cur = cur->next;
	if (g_global.child[this_pipe].infile != NULL)
		free(g_global.child[this_pipe].infile);
	g_global.child[this_pipe].infile = ft_strdup(((t_elem *)cur->content)->str);
	return (0);
}
