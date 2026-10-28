/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 20:47:27 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:10 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	size_t				i;

	ss = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char) c)
			return ((void *) & ss[i]);
		i++;
	}
	return (NULL);
}
