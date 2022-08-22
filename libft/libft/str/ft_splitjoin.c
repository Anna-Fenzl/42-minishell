/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:15:40 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/22 18:16:08 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_splitjoin(char **split, char *str)
{
	char	**ret;
	int		len;
	int		i;

	i = 0;
	if (split == NULL)
		return (ft_split(str, '\0'));
	len = ft_splitlen(split);
	if (str == NULL)
		return (split);
	ret = malloc(sizeof(char *) * (len + 2));
	if (ret == NULL)
		return (NULL);
	while (split && split[i] != NULL)
	{
		ret[i] = ft_strdup(split[i]);
		i++;
	}
	ret[i++] = ft_strdup(str);
	ret[i] = NULL;
	ft_free2(split);
	return (ret);
}
