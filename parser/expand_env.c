/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:47:18 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/27 17:43:31 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	in_env(char **split, int i)
{
	// int		j;
	// char	**tmp;

	// j = 0;
	// while (g_global.env[j])
	// {
	// 	tmp = ft_split(g_global.env[j], '=');//HOME = /home/sar
	// 	if (!ft_strncmp(split[i] + 1, tmp[0]//+`1 because our path begins with /
	// 			, ft_strlen(split[i] + 1)))
	// 	{
	// 		free(split[i]);
	// 		split[i] = ft_strdup(g_global.env[j] + len);//if HOME == HOME we clean our split and put env inside
	// 	}
	// 	ft_free2(tmp);
	// 	j++;
	// }
	int		line;
	char	*str;
	int		j;

	j = 0;
	line = check_existence(g_global.env, &split[i][1]);
	if (line != -1)
	{
		str = g_global.env[line];
		while (str != NULL && str[j] != '=' && str[j] != '\0')
			j++;
		if (str != NULL && str[j] == '=')
			j++;
		split[i] = ft_strdup(&str[j]);
	}
}

void	not_in_env(char **split, int i, int len)
{
	char	*res;

	if (split[i][0] == '$' && len != 1)
	{
		if (split[i][1] == '?' && len == 2)// true or false
		{
			free(split[i]);
			res = ft_itoa(g_global.error_code);
			split[i] = ft_strdup(res);
			free(res);
		}
		else//just print
		{
			free(split[i]);
			split[i] = ft_strdup("");
		}
	}
}

/***************
 * NAME: replace_var
 * INPUT:
 * RETURN:
 * DESCRIPTION: if we find the $ than we check the env
 *
 *
 ****************/
char	**replace_var(char **split_q, int index)
{
	char	**split;
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = split_q[index];
	split = ft_new_split(s);
	while (split[i])
	{
		len = ft_strlen(split[i]);
		if (split[i][0] == '$' && len != 1)
		{
			in_env(split, i);
			not_in_env(split, i, len);
		}
		else if (split[i][0] == '$')
		{
			if (split_q[index + 1] && (split_q[index + 1][0] == '\'' || split_q[index + 1][0] == '\"'))
				split[i] = ft_strdup("");
		}
		i++;
	}
	return (split);
}
