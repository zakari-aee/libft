/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstprint_str.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 22:15:54 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/20 22:26:26 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_str(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putendl_fd((char *) lst->content, 1);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*node3 = ft_lstnew("zakariae");
	t_list	*node1 = ft_lstnew("zakariae");
	t_list	*node2 = ft_lstnew("zakariae");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstprint_str(node1);
}
