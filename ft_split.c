/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:12:41 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/28 13:49:56 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_chunks(const char *str, char delimiter)
{
	size_t	chunk;
	int		is_inside_word;

	chunk = 0;
	is_inside_word = 0;
	while (*str)
	{
		if (*str != delimiter && !is_inside_word)
		{
			is_inside_word = 1;
			chunk++;
		}
		else if (*str == delimiter)
			is_inside_word = 0;
		str++;
	}
	return (chunk);
}

static char	*get_next_word(const char *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (ft_substr(s, 0, index));
}

static void	free_memory(char ***word_chunks, int allocated)
{
	char	**current;

	if (!word_chunks || !*word_chunks)
		return ;
	current = *word_chunks;
	while (allocated--)
	{
		free(*current);
		current++;
	}
	free(*word_chunks);
	*word_chunks = NULL;
}

static int	fill(char **word_chunks, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word_chunks[i] = get_next_word(s, c);
			if (!word_chunks[i])
			{
				free_memory(&word_chunks, i);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	word_chunks[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**word_chunks;
	size_t	chunks;

	if (!s)
		return (NULL);
	chunks = count_chunks(s, c);
	word_chunks = (char **)ft_calloc(chunks + 1, sizeof(char *));
	if (!word_chunks)
		return (NULL);
	if (!fill(word_chunks, s, c))
		return (NULL);
	return (word_chunks);
}
