/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:47:18 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/21 14:28:51 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	in_env(char **split, int i, int len)
{
	int		j;
	char	**tmp;

	j = 0;
	while (g_global.env[j])
	{
		tmp = ft_split(g_global.env[j], '=');//HOME = /home/sar
		if (!ft_strncmp(split[i] + 1, tmp[0]//+`1 because our path begins with /
				, ft_strlen(tmp[0])))
		{
			free(split[i]);
			split[i] = ft_strdup(g_global.env[j] + len);//if HOME == HOME we clean our split and put env inside
		}
		ft_free2(tmp);
		j++;
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
char	**replace_var(char *s)
{
	char	**split;
	int		i;
	int		len;

	i = 0;
	split = ft_split(s, '\0');//ft_new_split
	while (split[i])
	{
		len = ft_strlen(split[i]);
		if (split[i][0] == '$' && len != 1)
		{
			in_env(split, i, len);
			not_in_env(split, i, len);
		}
		i++;
	}
	return (split);
}
