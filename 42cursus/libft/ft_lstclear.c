/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:54:07 by haekang           #+#    #+#             */
/*   Updated: 2023/04/06 21:56:45 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*n_node;

	if (lst == NULL || *lst == NULL)
		return ;
	node = *lst;
	n_node = node->next;
	while (node != NULL)
	{
		(*del)(node->content);
		free(node);
		node = n_node;
		if (node != NULL)
			n_node = node->next;
	}
	*lst = NULL;
}
