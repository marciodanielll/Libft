/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md <md@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:50:24 by md                #+#    #+#             */
/*   Updated: 2024/10/23 19:11:07 by md               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	count;

	if (!s || !f)
		return (NULL);
	new_str = malloc((ft_strlen((const char *)s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	count = 0;
	while (s[count])
	{
		new_str[count] = f(count, s[count]);
		count++;
	}
	new_str[count] = '\0';
	return (new_str);
}