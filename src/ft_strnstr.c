/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:10:25 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/17 20:48:14 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	count;

	if (little)
		return ((void *)big);
	while (big && little && len--)
	{
		while (*big == *little)
		{
			big++;
			little++;
			count++;
		}
		if (*little == '\0')
		{
			big -= count;
			return ((char *)big);
		}
		big++;
	}
	return ((char *)big);
}
