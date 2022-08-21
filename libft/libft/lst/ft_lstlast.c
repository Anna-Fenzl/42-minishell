/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:44:44 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/21 14:41:20 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (lst != NULL)
	{
		i = ft_lstsize(lst) - 1;
		while (i--)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
