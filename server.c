/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:33:47 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/23 12:02:02 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
    static int bit_count = 0;
    static char c;
    static char    *mssg;

    if (sig == SIGUSR1)
        c |= (1 << (7 - bit_count));
    bit_count++;
    if (!mssg)
        mssg = ft_strdup("");
    if (bit_count == 8)
    {
        if (c == '\0')
        {
            ft_printf("%s", mssg);
            free(mssg);
            mssg = NULL;
        }
        else
        {
            mssg = ft_join(mssg, c);
            if (!mssg)
                return;
        }
        bit_count = 0;
        c = 0;
    }
}

int main()
{
    int pid = getpid();
    
    printf("Server PID: %d\n", pid);
    signal(SIGUSR1,signal_handler);
    signal(SIGUSR2,signal_handler);

    while (1)
        pause();

    return 0;
}
