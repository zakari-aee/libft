/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/16 19:06:19 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/16 19:06:28 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstt;
	const unsigned char	*srcc;
	size_t				i;

	dstt = (unsigned char *) dst;
	srcc = (const unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dstt < srcc)
	{
		while (len--)
		{
			dstt[i] = srcc[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			dstt[len] = srcc[len];
		}
	}
	return (dst);
}
