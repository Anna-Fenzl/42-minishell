/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:16:15 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/03 21:15:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	if (tmp != NULL && f != NULL)
	{
		i = ft_lstlen(lst);
		while (i--)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
