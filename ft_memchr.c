/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 14:14:52 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/19 14:14:53 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		t;

	p = (const unsigned char *) s;
	t = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (p[i] == t)
			return ((void *) & p[i]);
		i++;
	}
	return (NULL);
}
