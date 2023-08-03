/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:54:07 by haekang           #+#    #+#             */
/*   Updated: 2023/04/07 16:33:32 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	node = *lst;
	next = node->next;
	while (node != NULL)
	{
		ft_lstdelone(node, (*del));
		node = next;
		if (node != NULL)
			next = node->next;
	}
	*lst = NULL;
}
