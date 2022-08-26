/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:02:32 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/26 17:47:59 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*join(char *s1, char *s2, char *new)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	join(s1, s2, new);
	free(s1);
	free(s2);
	return (new);
}

char	**get_possible_paths(char **env)
{
	int		i;
	char	**split;

	i = 0;
	split = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			split = ft_split(&(env[i][5]), ':');
			break ;
		}
		i++;
	}
	return (split);
}

char	*check_access(char **split, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (split != NULL && split[i] != NULL && cmd != NULL)
	{
		split[i] = ft_strjoin2(split[i], ft_strdup("/"));
		split[i] = ft_strjoin2(split[i], ft_strdup(cmd));
		if (access(split[i], F_OK) == 0)
		{
			tmp = ft_strdup(split[i]);
			ft_free2(split);
			return (tmp);
		}
		i++;
	}
	return (tmp);
}

//  && access(cmd, 0) == 0
char	*ft_get_path(char *cmd)
{
	char	**split;
	char	*tmp;

	if (ft_strchr(cmd, '/') != 0)
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		return (NULL);
	}
	split = get_possible_paths(g_global.env);
	tmp = check_access(split, cmd);
	if (tmp != NULL)
		return (tmp);
	if (split != NULL)
		ft_free2(split);
	return (ft_strjoin("./", cmd));
}
