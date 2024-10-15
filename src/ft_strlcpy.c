/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:20:17 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/14 21:51:19 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    char *ptr_s; 
    int len;

    ptr_s = (char*)src;
    len = 0;
    while(*ptr_s  && size--)
    {
        dst++ = ptr_s ++;
        len++;
    }
    return(len);
}
