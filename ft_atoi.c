/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:03:57 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/30 11:37:35 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long res, int s)
{
	int		t;
	long	r;

	t = 5;
	r = 0;
	r = res * t;
	if (r / t != res)
	{
		if (s < 0)
			return (0);
		return (-1);
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	char	*s;
	long	res;
	int		sign;
	int		i;

	s = (char *)nptr;
	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (ft_check((res * sign), sign));
}
