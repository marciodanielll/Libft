/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:11:03 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/27 19:24:30 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_elem;

	ptr = NULL;
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			new_elem = ft_lstnew(f(lst->content));
			if (!new_elem)
			{
				ft_lstclear(&ptr, del);
				return (NULL);
			}
			ft_lstadd_back(&ptr, new_elem);
			lst = lst->next;
		}
	}
	return (ptr);
}
