/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:59:44 by mhermini          #+#    #+#             */
/*   Updated: 2025/04/02 00:19:39 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str)
{
	int	char_written;

	char_written = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		char_written += ft_putchar(*str);
		str++;
	}
	return (char_written);
}
