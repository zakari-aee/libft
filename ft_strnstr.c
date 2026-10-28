/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/14 13:16:48 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:49 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	l;

	if (!*s2)
		return ((char *) s1);
	i = 0;
	while (s1[i] && i < len)
	{
		l = 0;
		while (s1[i + l] && (s1[i + l] == s2[l]) && (i + l < len))
		{
			l++;
			if (!s2[l])
				return ((char *) & s1[i]);
		}
		i++;
	}
	return (NULL);
}
