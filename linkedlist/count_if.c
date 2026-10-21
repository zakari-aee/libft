/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   count_if.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 12:59:40 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 13:06:02 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_if(t_list *lst, int (*f)(void *))
{
	int	c = 0;

	if (!lst)
		return (0);
	while (lst)
	{
		if (f(lst->content) != 0)
			c++;
		lst = lst->next;
	}
	return (c);
}

static int	is_neg(void *t)
{
	int	*res;

	res = (int *) t;
	if (*res > 0)
		return (1);
	return (0);
}

int	main(void)
{
	t_list	*head = NULL;
	int		a = 10;
	int		b = 20;
	int		c = -30;

	ft_lstadd_front(&head, ft_lstnew(&a));
	ft_lstadd_front(&head, ft_lstnew(&b));
	ft_lstadd_front(&head, ft_lstnew(&c));
	printf("%d", count_if(head, is_neg));
}
