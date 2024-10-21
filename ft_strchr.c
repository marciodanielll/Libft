/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:58:44 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/21 17:56:16 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	parse_c;

	parse_c = (unsigned int)c;
	while (*s != '\0')
	{
		if (*s == parse_c)
			return ((char *)s);
		s++;
	}
	if (*s == parse_c)
		return ((char *)s);
	return (NULL);
}
