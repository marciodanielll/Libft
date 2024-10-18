/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:10:25 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/17 22:20:17 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_start;
	const char	*little_start;

	if (*little == '\0')
		return ((char *)big);
	little_start = little;
	while (*big != '\0' && len)
	{
		big_start = big;
		little = little_start;
		while (*big == *little && len)
		{
			big++;
			little++;
			len--;
			if (*little == '\0')
				return ((char *)big_start);
		}
		big = big_start + 1;
		len--;
	}
	return (NULL);
}
