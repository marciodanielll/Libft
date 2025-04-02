/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:11:42 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/28 21:32:51 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*ptr_s1;
	size_t			start;
	size_t			end;
	size_t			s1_len;

	start = 0;
	s1_len = ft_strlen(s1);
	end = s1_len;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	ptr_s1 = (unsigned char *)malloc((end - start + 1) * sizeof(char));
	if (!ptr_s1)
		return (NULL);
	ft_strlcpy((char *)ptr_s1, s1 + start, end - start + 1);
	return ((char *)ptr_s1);
}
