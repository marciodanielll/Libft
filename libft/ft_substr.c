/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:45:44 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:21 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*original_ptr;
	size_t	total_size;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	total_size = (len + 1) * sizeof(char);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	original_ptr = ptr;
	s += start;
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (original_ptr);
}
