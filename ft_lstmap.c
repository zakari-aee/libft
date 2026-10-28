/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 15:39:38 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:31:53 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*con;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		con = f(lst->content);
		new_node = ft_lstnew(con);
		if (!new_node)
		{
			del(con);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
