/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by mhermini          #+#    #+#             */
/*   Updated: 2025/04/02 03:09:31 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				char_written;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	char_written = 0;
	char_written += ft_putstr("0x");
	char_written += ft_print_hex_with_case(addr, 0);
	return (char_written);
}
