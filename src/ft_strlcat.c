/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:12:15 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/15 14:24:43 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dst_len;
	size_t		remaining;

	d = dst;
	s = src;
	remaining = size;
	while (remaining-- != 0 && *d != '\0')
		d++;
	dst_len = d - dst;
	remaining = size - dst_len;
	if (remaining == 0)
		return (dst_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (remaining > 1)
		{
			*d++ = *s;
			remaining--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
