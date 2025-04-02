/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:44 by mhermini          #+#    #+#             */
/*   Updated: 2025/04/02 03:57:52 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
static t_message g_current_message = {0, 0};

void append_character_to_message(void)
{
    char *updated_message;
    char tmp[2];

    tmp[0] = (char)g_current_message.c;
    tmp[1] = '\0';

    if (g_current_message.msg)
    {
        updated_message = ft_strjoin(g_current_message.msg, tmp);
        free(g_current_message.msg);
    }
    else
    {
        updated_message = ft_strdup(tmp);
    }
    if (!updated_message)
        exit(EXIT_FAILURE);
    
    g_current_message.msg = updated_message;
}

void handle_complete_character(void)
{
    if (g_current_message.c == '\0')
    {
        if (g_current_message.msg)
            ft_printf("%s\n", g_current_message.msg);
        else
            ft_printf("\n");
        free(g_current_message.msg);
        g_current_message.msg = NULL;
    }
    else
    {
        append_character_to_message();
    }
    g_current_message.c = 0;
}

void handle_signal(int signal, siginfo_t *client_info, void *context)
{
    static int received_bit_count = 0;
    (void)context;

    if (signal == SIGUSR1)
        g_current_message.c = (g_current_message.c << 1) | 1;
    else if (signal == SIGUSR2)
        g_current_message.c = (g_current_message.c << 1);

    received_bit_count++;

    if (received_bit_count == 8)
    {
        handle_complete_character();
        received_bit_count = 0;
    }
    
    if (kill(client_info->si_pid, SIGUSR1) == -1)
        exit(EXIT_FAILURE);
}

int main(void)
{
    struct sigaction signal_action;
    ft_printf("Server PID: %d\n", getpid());

    signal_action.sa_sigaction = handle_signal;
    signal_action.sa_flags = SA_SIGINFO;
    sigemptyset(&signal_action.sa_mask);

    sigaction(SIGUSR1, &signal_action, NULL);
    sigaction(SIGUSR2, &signal_action, NULL);

    while (1)
        pause();

    return (EXIT_SUCCESS);
}

