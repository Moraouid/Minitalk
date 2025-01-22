/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:33:47 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/22 19:53:07 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int bit_count = 0;
    static char current_char = 0;
    static pid_t client_pid = 0;
    char    *mssg;
    char    *tmp;

    if (client_pid == 0)
        client_pid = info->si_pid;
    if (sig == SIGUSR1)
        current_char |= (1 << (7 - bit_count));
    bit_count++;
    tmp = &current_char;
    if (bit_count == 8)
    {
        if (current_char == '\0')
        {
            ft_printf("%s", mssg);
            free(mssg);
            mssg = NULL;
        }
        else
        {
            tmp = ft_strjoin(mssg, ft_ctostr(current_char));
            if (!tmp)
            {
                if (mssg)
                    free(mssg);
                mssg = NULL;
                return;
            }
        }
        bit_count = 0;
        current_char = 0;
    }
    kill(client_pid, SIGUSR1);
}

int main()
{
    pid_t pid = getpid();
    struct sigaction sa;
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    printf("Server PID: %d\n", pid);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return 0;
}
