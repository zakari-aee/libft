/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:36:44 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/27 13:13:43 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_len(long n)
{
	int	c;

	c = 1;
	if (n < 0)
	{
		n = n * -1;
		c++;
	}
	while (n >= 10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*r;
	long	i;
	long	len;
	i = n;
	len = atoi_len(n);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	if (i < 0)
	{
		i = -i;
		r[0] = '-';
	}
	len--;
	while (i >= 10)
	{
		r[len] = (i % 10) + '0';
		i /= 10;
		len--;
	}
	r[len] = i + '0';
	return (r);
}