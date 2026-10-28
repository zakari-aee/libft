/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/15 12:39:40 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:40 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*r;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r = malloc(len_s1 + len_s2 + 1);
	if (r == 0)
		return (NULL);
	r[0] = '\0';
	ft_strlcat(r, s1, len_s1 + 1);
	ft_strlcat(r, s2, len_s1 + len_s2 + 1);
	return (r);
}
