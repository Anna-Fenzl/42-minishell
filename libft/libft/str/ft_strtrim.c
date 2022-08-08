/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:45:04 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 18:57:55 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (set == NULL || s1 == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	count = ft_strlen(s1);
	while (count > i && ft_strchr(set, s1[count]))
		count--;
	return (ft_substr(s1, i, count - i + 1));
}
