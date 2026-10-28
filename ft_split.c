/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: zallioua <zallioua@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/15 14:42:47 by zallioua         #+#    #+#              */
/*   Updated: 2026/10/27 11:32:27 by zallioua        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

static int	count_w(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	if (!s || s[0] == '\0')
		return (0);
	i = 1;
	if (!is_sep(s[0], c))
		count++;
	while (s[i] != '\0')
	{
		if (!is_sep(s[i], c) && is_sep(s[i - 1], c))
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **str, int place)
{
	while (place > 0)
		free(str[--place]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(count_w(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (!is_sep(s[i], c))
		{
			result[++j] = word_dup(&s[i], c);
			if (!result[j])
				return (ft_free(result, j));
			while (s[i] && !is_sep(s[i], c))
				i++;
		}
		else
			i++;
	}
	return (result);
}
