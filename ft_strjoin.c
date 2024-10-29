/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 05:10:50 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/28 21:31:02 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ptr;
	unsigned char	*ptr_original;
	size_t			size_s1;
	size_t			size_s2;
	size_t			total_size;

	size_s1 = ft_strlen(s1) * sizeof(char);
	size_s2 = ft_strlen(s2) * sizeof(char);
	total_size = size_s1 + size_s2 + 1;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ptr_original = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return ((char *)ptr_original);
}
