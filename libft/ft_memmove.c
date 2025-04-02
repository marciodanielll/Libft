/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:32:57 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/21 20:54:58 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!n || (src == dest))
		return (dest);
	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (destination > source)
	{
		destination += n;
		source += n;
		while (n--)
			*--destination = *--source;
		return (dest);
	}
	while (n--)
		*destination++ = *source++;
	return (dest);
}
