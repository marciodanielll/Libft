/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:42:38 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/21 21:50:10 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*source;
	unsigned char		compare;

	compare = (unsigned char)c;
	source = (const unsigned char *)s;
	while (n--)
	{
		if (*source == compare)
		{
			return ((void *)source);
		}
		source++;
	}
	return (NULL);
}
