/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:15:16 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/18 13:58:48 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	rem_old_var(char ***env, char *str, int line)
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

int	builtin_unset(char ***env, char *str)
{
	int	line;
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) != 1 && str[i] != '_')
		{
			printf("minishell: unset: `%s\': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	line = check_existence(*env, str);
	if (line >= 0)
	{
		rem_old_var(env, str, line);
	}
	return (0);
}
