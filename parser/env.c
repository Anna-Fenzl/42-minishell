/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:47:18 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/19 18:54:07 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_env(char **split, int i, int len)
{
	int		j;
	char	**tmp;

	j = 0;
	while (g_ms.cpenv[j])
	{
		tmp = ft_split(g_ms.cpenv[j], '=');//HOME = /home/sar
		if (!ft_strncmp(split[i] + 1, tmp[0]//+`1 because our path begins with /
				, ft_strlen(tmp[0])))
		{
			free(split[i]);
			split[i] = ft_strdup(g_ms.cpenv[j] + len);//if HOME == HOME we clean our split and put env inside
		}
		free_split(tmp);
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
			res = ft_itoa(g_ms.ret);
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
	split = ft_new_split(s);
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
