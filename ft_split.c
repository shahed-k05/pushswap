/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:16:31 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:16:33 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*split_word(const char *s, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i + start];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static int	word_len(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = malloc((count_word(s, c) + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = split_word(s, i, word_len(s, i, c));
			if (!res[j])
				return (free_all(res, j), NULL);
			i += word_len(s, i, c);
			j++;
		}
	}
	return (res[j] = NULL, res);
}
