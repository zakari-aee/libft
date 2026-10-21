/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstprint_str.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 22:15:54 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 09:38:39 by zallioua        ###   ########.fr        */
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
