/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:30 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/02 06:19:43 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>

typedef struct s_message
{
	unsigned char	c;
	char			*msg;
}t_message;

#endif
