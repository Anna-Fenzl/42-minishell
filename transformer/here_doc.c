/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:51:53 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/30 18:57:09 by afenzl           ###   ########.fr       */
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

void	here_doc_signal(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		exit(1);
	}
}

void	here_doc(t_list *cur)
{
	char	*delim;
	char	*input;
	int		fd;

	signal(SIGINT, here_doc_signal);
	cur = cur->next;
	if (create_tmpfile(&fd) == 1)
		exit(1);
	write(1, "here_doc> ", 10);
	delim = ft_strjoin(((t_elem *)cur->content)->str, "\n");
	input = get_next_line(STDIN_FILENO);
	while (input != NULL
		&& ft_strncmp(input, delim, ft_strlen(input) + 1) != 0)
	{
		if (((t_elem *)cur->content)->quotes == 0)
			input = expand_variables(input);
		ft_putstr_fd(input, fd);
		free(input);
		write(1, "here_doc> ", 10);
		input = get_next_line(STDIN_FILENO);
	}
	free(delim);
	free(input);
	exit(0);
}
