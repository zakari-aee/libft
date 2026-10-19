/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:52:34 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/19 12:54:19 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstt;
	const unsigned char	*srcc;

	dstt = (unsigned char *) dst;
	srcc = (const unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	d[8];
	char	s[] = "zakariae";
	size_t	n = 8;

	ft_memcpy(d, s, n);
	printf("%s", d);
}
