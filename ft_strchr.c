/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 14:12:40 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/19 14:12:45 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char) c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == t)
			return ((char *) s);
		i++;
	}
	if (t == '\0')
		return ((char *) s);
	return (NULL);
}
