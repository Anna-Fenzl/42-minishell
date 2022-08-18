/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:10 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 20:44:26 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	also export can be called with more than one argument
	-> invalid ones are not added, valid ones are - order doesnt matter
	original export prints variables in alphabetical order -- env doesnt
*/
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
	else if (check_name(str) == 1)
	{
		printf("minshell: export: `%s': not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	else if (line >= 0)
		change_value(*env, str, line);
	else
		set_new_var(env, str);
	return (EXIT_SUCCESS);
}
