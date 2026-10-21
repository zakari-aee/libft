/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   find.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:06:49 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 13:18:57 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find(t_list *lst, void *ref, int (*cmp)(void *, void *))
{
	if (!lst || !ref || !cmp)
		return (NULL);
	while (lst)
	{
		if ((cmp(ref, lst->content)) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static int	cmp(void *s1, void *s2)
{
	unsigned char	*ss1 = s1;
	unsigned char	*ss2 = s2;
	unsigned int	i = 0;

	while (ss1[i] && ss2[i] && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

int	main(void)
{
	int		aa = 10;
	int		*ref = &aa;
	t_list	*head = NULL;
	int		a = 210;
	int		b = 20;
	int		c = -30;

	ft_lstadd_front(&head, ft_lstnew(&a));
	ft_lstadd_front(&head, ft_lstnew(&b));
	ft_lstadd_front(&head, ft_lstnew(&c));
	t_list	*res = find(head, ref, cmp);

	printf("%d", *(int *) res->content);
}
