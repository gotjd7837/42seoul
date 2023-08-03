/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:04:47 by haekang           #+#    #+#             */
/*   Updated: 2023/04/07 16:35:06 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*content_p;

	if (lst == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		content_p = (*f)(lst->content);
		new_node = ft_lstnew(content_p);
		if (new_node == NULL)
		{
			ft_lstclear(&head, (*del));
			(*del)(content_p);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&head, new_node);
			lst = lst->next;
		}
	}
	return (head);
}
