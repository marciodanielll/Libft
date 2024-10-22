/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md <md@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 9:15:49 by md                #+#    #+#             */
/*   Updated: 2024/10/22 16:56:21 by md               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	handle_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static void	free_words(char **words, size_t i)
{
	while (--i)
		free(words[i]);
	free(words);
}

static int	fill(char **words, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			words[i] = get_next_word(s, c);
			if (!words[i])
			{
				free_words(words, i);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	words[i] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = handle_count(s, c);
	words = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	if (!fill(words, s, c))
		return (NULL);
	return (words);
}
