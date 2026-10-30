/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:18:56 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/30 11:41:16 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				len;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	len = 0;
	while (len < n)
	{
		d[len] = s[len];
		len++;
	}
	return (d);
}
