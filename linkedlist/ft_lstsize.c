/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstsize.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 22:31:49 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/20 22:36:34 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	c;

	c = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

int	main(void)
{
	t_list	*node3 = ft_lstnew("zakariae");
	t_list	*node1 = ft_lstnew("zakariae");
	t_list	*node2 = ft_lstnew("zakariae");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("%d", ft_lstsize(node1));
}
