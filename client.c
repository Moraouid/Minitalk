/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:33:39 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/22 19:19:27 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int check;

void signal_check(int sig)
{
	check = 1;
}

void send_char(int pid, char c)
{
	int i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		while (!signal_check)
			pause();
		check = 0;
		i--;
	}
}

int main(int ac, char **av)
{
	int pid;
	int i = 0;
	struct sigaction sa;
    sa.sa_handler = signal_check;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

	if (ac != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 31);
		return 1;
	}
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID\n", 12);
		return 1;
	}
	sigaction(SIGUSR1, &sa, NULL) ;	
	while (av[2][i] != '\0')
	{
		send_char(pid, av[2][i]);
		i++;
		usleep(100);
	}
	send_char(pid, '\0');
}
