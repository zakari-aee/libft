/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 14:17:44 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/19 14:17:48 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *) hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len && hay[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
