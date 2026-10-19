/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/16 19:05:38 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/19 12:48:01 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		z[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
