/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   node_from_int.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 12:42:27 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 12:48:55 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

static t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!content)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*node_from_int(int n)
{
	t_list	*node;
	int		*val;

	val = malloc(sizeof(int));
	if (!val)
		return (NULL);
	*val = n;
	node = ft_lstnew(val);
	if (!node)
		free(val);
	return (node);
}

int	main(void)
{
	t_list	*node = node_from_int(10);

	printf("%d", *(int *) node->content);
}
