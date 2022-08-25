/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:01:46 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/25 15:34:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	checks until '\0' or '=' if NAME is existent in env
*/
int	check_existence(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str == NULL)
		return (-1);
	while (env != NULL && env[i] != NULL)
	{
		j = 0;
		while (env[i] && env[i][j] != '\0' && str[j] != '\0'
			&& env[i][j] == str[j])
		{
			if (env[i][j + 1] == '=' || env[i][j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

/*
	checks until '=' if the name is valid (alnum && '_')
*/
int	check_name(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '=')
	{
		if (ft_isalnum(str[i]) != 1 && str[i] != '_')
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	return (0);
}

/*
	export_alone: prints until '=' od '\0'
*/
void	print_name(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '=' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str != NULL && str[i] == '=')
		write(1, &str[i++], 1);
}

/*
	export_alone: prints value in double quotes after '='
*/
void	print_value(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '=' && str[i] != '\0')
		i++;
	if (str != NULL && str[i] == '=')
	{
		i++;
		write(1, "\"", 1);
		while (str && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\"", 1);
	}
}
