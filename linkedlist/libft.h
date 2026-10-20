/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libft.h                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 22:09:10 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/20 22:38:50 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
typedef struct s_list

{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstprint_str(t_list *lst);
void			ft_putendl_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);

#endif
