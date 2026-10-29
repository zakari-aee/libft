/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:35:39 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/29 07:16:54 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define SIZE 64

static int	check(size_t dst_off, size_t src_off, size_t n)
{
	unsigned char	a[SIZE];
	unsigned char	b[SIZE];
	unsigned char	*ra;
	unsigned char	*rb;
	size_t			i;

	for (i = 0; i < SIZE; i++)
		a[i] = b[i] = (unsigned char) i;
	ra = memmove(a + dst_off, a + src_off, n);
	rb = ft_memmove(b + dst_off, b + src_off, n);
	if (memcmp(a, b, SIZE) != 0 || (ra - a) != (rb - b))
	{
		printf("FAIL dst=%zu src=%zu n=%zu\n", dst_off, src_off, n);
		return (1);
	}
	return (0);
}

int	main(void)
{
	size_t	d, s, n;
	int		fails = 0;
	char	buf1[] = "hello world";
	char	buf2[] = "hello world";

	for (d = 0; d <= SIZE / 2; d++)
		for (s = 0; s <= SIZE / 2; s++)
		for (n = 0; n <= SIZE / 2; n++)
		fails += check(d, s, n);
	/* src == dest must return dest */
	if (ft_memmove(buf1, buf1, 5) != buf1)
		fails++, printf("FAIL src == dest return value\n");
	/* non-overlapping, different buffers */
	memmove(buf1, "abcde", 5);
	ft_memmove(buf2, "abcde", 5);
	if (strcmp(buf1, buf2) != 0)
		fails++, printf("FAIL separate buffers\n");
	/* n == 0 must not touch anything */
	ft_memmove(buf2, "zzzzz", 0);
	if (strcmp(buf1, buf2) != 0)
		fails++, printf("FAIL n == 0\n");
	printf(fails ? "%d test(s) failed\n" : "All tests passed\n", fails);
	return (fails != 0);
}
