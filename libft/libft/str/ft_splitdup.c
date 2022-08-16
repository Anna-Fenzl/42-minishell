/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:27:32 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/16 14:35:40 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_splitdup(char **split)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc((ft_splitlen(split) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (split != NULL && split[i] != NULL)
	{
		ret[i] = ft_strdup(split[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
