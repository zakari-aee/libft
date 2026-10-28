/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_bzero.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/12 19:13:37 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:31:09 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			len;
	unsigned char	*z;

	z = (unsigned char *) s;
	len = 0;
	while (len < n)
	{
		z[len] = '\0';
		len++;
	}
}
