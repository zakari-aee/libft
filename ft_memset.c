/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:35:26 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/30 11:42:12 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;
	char	*z;

	z = (char *)s;
	len = 0;
	while (len < n)
	{
		z[len] = (char)c;
		len++;
	}
	return (s);
}
