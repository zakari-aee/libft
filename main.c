/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zallioua <zallioua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:41:31 by zallioua          #+#    #+#             */
/*   Updated: 2026/10/29 08:44:26 by zallioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int a)
{
	char	c;
	long	len = ft_len(a);
	long	len1 = ft_len(a);
	long	rev = 0;

	if (a < 0)
	{
		write(1, "-", 1);
		a = -a;
	}
	while (len > 0)
	{
		rev = (rev * 10) + (a % 10);
		a /= 10;
		len--;
	}
	while (len1 > 0)
	{
		c = (rev % 10) + '0';
		write(1, &c, 1);
		rev /= 10;
		len1--;
	}
}

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#include <stdio.h>

int	main(void)
{
	unsigned char	x;
	unsigned char	y;

	unsigned char	a[] = {10 , 20 , 30};
	unsigned char	b[] = {10 , 20 , 30};
	unsigned char	*p = a;
	unsigned char	*q = b;

	x = *p++;
	y = (*q)++;
	printf("*p++   : x=%d  *p=%d  p-a=%ld  array: %d %d %d\n",
		x, *p, p - a, a[0], a[1], a[2]);
	printf("(*q)++ : y=%d  *q=%d  q-b=%ld  array: %d %d %d\n",
		y, *q, q - b, b[0], b[1], b[2]);
	return (0);
}
