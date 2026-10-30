/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 13:47:53 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/30 11:46:56 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	if (c == '\0')
		return ((char *) & s[len_s]);
	while (len_s > 0)
	{
		len_s--;
		if (s[len_s] == (char) c)
			return ((char *) & s[len_s]);
	}
	return (NULL);
}
