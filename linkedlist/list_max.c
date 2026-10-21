/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   list_max.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 10:00:41 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 10:15:55 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	list_max(t_list *head, int *max)
{
	int	res;

	if (!head || !max)
		return (-1);
	res = *(int *) head->content;
	while (head)
	{
		if (*(int *) head->content > res)
			res = *(int *) head->content;
		head = head->next;
	}
	*max = res;
	return (res);
}

int	main(void)
{
	int		max;
	int		a = 10;
	int		b = 20;
	int		c = 30;
	t_list	*node3 = ft_lstnew(&a);
	t_list	*node1 = ft_lstnew(&b);
	t_list	*node2 = ft_lstnew(&c);

	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);
	ft_lstprint_str(node1);
	list_max(node1, &max);
	printf("%d", max);
}
