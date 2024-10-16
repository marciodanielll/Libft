/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:20:17 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/15 09:37:54 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr_s;
	size_t	len;
	size_t	i;

	len = 0;
	if (!src)
		return (0);
	ptr_s = (char *)src;
	len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		ptr_s = (char *)src;
		while (i < len && i < size - 1)
		{
			dst[i] = *ptr_s++;
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
