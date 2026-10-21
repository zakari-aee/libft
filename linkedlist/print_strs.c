/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_strs.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 12:57:09 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/21 12:59:02 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_strs(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*head = NULL;

	ft_lstadd_front(&head, ft_lstnew("zakariae"));
	ft_lstadd_front(&head, ft_lstnew("alliooate"));
	ft_lstadd_front(&head, ft_lstnew("aicha"));
	print_strs(head);
}
