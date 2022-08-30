/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:47:18 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/30 15:02:23 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	in_env(char **split, int i)
{
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
		free(split[i]);
		split[i] = ft_strdup(&str[j]);
	}
}

void	not_in_env(char **split, int i, int len)
{
	char	*res;

	if (split[i][0] == '$' && len != 1)
	{
		if (split[i][1] == '?' && len == 2)
		{
			free(split[i]);
			res = ft_itoa(g_global.error_code);
			split[i] = ft_strdup(res);
			free(res);
		}
		else
		{
			free(split[i]);
			split[i] = ft_strdup("");
		}
	}
}

void	check_env(char **split, int i, int len)
{
	in_env(split, i);
	not_in_env(split, i, len);
}

/***************
 * NAME: replace_var
 * INPUT:
 * RETURN:
 * DESCRIPTION: if we find the $ than we check the env
 *	else if: if $"" the $ is removed
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
			check_env(split, i, len);
		else if (split[i][0] == '$')
		{
			if (split_q[index + 1] && (split_q[index + 1][0] == '\''
				|| split_q[index + 1][0] == '\"'))
			{
				free(split[i]);
				split[i] = ft_strdup("");
			}
		}
		i++;
	}
	return (split);
}
