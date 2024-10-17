/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:19:02 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/17 17:56:07 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr_s;

	ptr_s = (char *)src;
	if (size > 0)
	{
		while (*src && (size - 1))
		{
			*dst++ = (char)*src++;
			size--;
		}
		*dst = '\0';
	}
	return (ft_strlen(ptr_s));
}
