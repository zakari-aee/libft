/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcpy.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 11:50:00 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:44 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	src_len;

	src_len = ft_strlen((char *) src);
	if (size == 0)
	{
		return (src_len);
	}
	l = 0;
	while (src[l] && l < size - 1)
	{
		dst[l] = src[l];
		l++;
	}
	dst[l] = '\0';
	return (src_len);
}
