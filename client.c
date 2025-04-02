/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:22:28 by mhermini          #+#    #+#             */
/*   Updated: 2025/04/02 02:55:04 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal_received = 0;

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_signal_received = 1;
}

void	transmit_message(int server_pid, char *message, size_t message_length)
{
	size_t	char_index;
	int		bit_index;

	char_index = 0;
	while (char_index < message_length)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if ((message[char_index] >> (7 - bit_index)) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bit_index++;
			usleep(10000);
			while (!g_signal_received)
				pause();
			g_signal_received = 0;
		}
		char_index++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <Server PID> <Message>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid Server PID.\n");
		return (1);
	}
	signal(SIGUSR1, handle_signal);
	transmit_message(server_pid, argv[2], ft_strlen(argv[2]) + 1);
	return (0);
}
