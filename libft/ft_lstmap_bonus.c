/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:05:36 by macote            #+#    #+#             */
/*   Updated: 2023/03/01 14:19:58 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*clear(t_list *content, t_list *head, void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(&head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	t_list	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (clear(content, head, del));
			
		new_node = ft_lstnew(content);
		if (!new_node)
			return (clear(content, head, del));
			
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
