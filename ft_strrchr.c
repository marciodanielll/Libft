/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:40 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/21 17:38:32 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	value;
	char	*ptr_result;
	char	*ptr_s;

	ptr_result = NULL;
	value = (char)c;
	ptr_s = (char *)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == value)
			ptr_result = ptr_s;
		ptr_s++;
	}
	if (*ptr_s == value)
		ptr_result = ptr_s;
	return (ptr_result);
}
