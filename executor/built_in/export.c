/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:10 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 16:29:57 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// spaces not handled the string must be trimmed
// also export can be called with more than one argument
// original export prints variables in alphabetical order -- env doesnt
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

void	export_alone(char ***env)
{
	int	i;

	i = 0;
	while (*env && (*env)[i] != NULL)
	{
		ft_printf("declare -x ");
		print_name((*env)[i]);
		print_value((*env)[i]);
		ft_printf("\n");
		i++;
	}
}

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

void	change_value(char **env, char *str, int line)
{
	if (ft_strchr(str, '=') != NULL)
	{
		free(env[line]);
		env[line] = ft_strdup(str);
	}
}

void	set_new_var(char ***env, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc((ft_splitlen(*env) + 2) * sizeof(char *));
	if (tmp == NULL)
		return ;
	while (*env != NULL && (*env)[i] != NULL)
	{
		tmp[i] = ft_strdup((*env)[i]);
		i++;
	}
	tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	ft_free2(*env);
	*env = tmp;
}

int	builtin_export(char ***env, char *str)
{
	int		line;

	line = check_existence(*env, str);
	if (str == NULL)
		export_alone(env);
	else if (line >= 0)
		change_value(*env, str, line);
	else
		set_new_var(env, str);
	return (0);
}
