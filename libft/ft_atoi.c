/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:28:50 by mhermini          #+#    #+#             */
/*   Updated: 2024/10/21 19:55:47 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_space(const char **str)
{
	while ((**str == ' ') || (**str >= 9 && **str <= 13))
		(*str)++;
}

static void	handle_sign(const char **str, int *number)
{
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*number = -1;
		(*str)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	converted;

	sign = 1;
	result = 0;
	handle_space(&nptr);
	handle_sign(&nptr, &sign);
	while (ft_isdigit(*nptr))
	{
		converted = *nptr - '0';
		result = (result * 10) + converted;
		nptr++;
	}
	return (result * sign);
}
