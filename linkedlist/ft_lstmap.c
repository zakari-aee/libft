/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:37:00 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 13:47:16 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*content;

	content = lst;
	while (lst)
	{
		res = f(content->content);
		if (!res)
		{
			del(res->content);
			free(res);
			return (NULL);
		}
		content = content->next;
	}
	return (res);
}
