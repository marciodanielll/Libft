/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:48:40 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/17 19:44:35 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len_s;
	char			*ptr_s;

	ptr_s = (char *)s;
	len_s = ft_strlen(s);
	ptr_s += len_s;
	if (*ptr_s == (char)c)
		return (ptr_s);
	while (ptr_s >= s)
	{
		if (*ptr_s == (char)c)
			return (ptr_s);
		ptr_s--;
	}
	return (NULL);
}
