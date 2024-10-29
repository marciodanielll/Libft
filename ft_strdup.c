/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:31:59 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/28 21:31:16 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*original_dup;
	size_t	total_size;

	total_size = (ft_strlen(s) + 1) * sizeof(char);
	dup = malloc(total_size);
	if (!dup)
		return (NULL);
	original_dup = dup;
	while (--total_size)
		*dup++ = *s++;
	*dup = '\0';
	return (original_dup);
}
