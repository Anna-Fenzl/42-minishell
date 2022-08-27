/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:16 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/27 14:36:23 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	rem_old_var(char ***env, int line)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = malloc((ft_splitlen(*env)) * sizeof(char *));
	if (tmp == NULL)
		return ;
	while (*env != NULL && (*env)[j] != NULL)
	{
		if (j != line)
		{
			tmp[i] = ft_strdup((*env)[j]);
			i++;
		}
		j++;
	}
	tmp[i] = NULL;
	ft_free2(*env);
	*env = tmp;
}

int	handle_unset(char ***env, char *str)
{
	int	line;
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		ft_printf_fd(2, "minishell: unset: `%s': not a valid identifier\n", str);
		return (EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) != 1 && str[i] != '_')
		{
			ft_printf_fd(2, "minishell: unset: `%s': not a valid identifier\n",
				str);
			return (EXIT_FAILURE);
		}
		i++;
	}
	line = check_existence(*env, str);
	if (line >= 0)
	{
		rem_old_var(env, line);
	}
	return (EXIT_SUCCESS);
}

int	builtin_unset(char ***env, char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (handle_unset(env, args[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
