/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/12 19:35:39 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:03 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				l;

	l = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d > s)
	{
		l = n;
		while (l > 0)
		{
			l--;
			d[l] = s[l];
		}
	}
	else
	{
		while (l < n)
		{
			d[l] = s[l];
			l++;
		}
	}
	return (d);
}
