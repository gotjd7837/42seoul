/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:04:47 by haekang           #+#    #+#             */
/*   Updated: 2023/04/06 21:55:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*sibal;

	new_lst = ft_lstnew((*f)(lst->content));
	if (new_lst != NULL)
		return (NULL);
	sibal = new_lst;
	while (lst != NULL)
	{
		lst = lst->next;
		if (lst != NULL)
		{
			ft_lstadd_back(&new_lst, sibal);
			sibal = sibal->next;
		}
	}
	sibal->next = NULL;

	ft_lstclear(&lst, (*del));

	return (new_lst);
}
