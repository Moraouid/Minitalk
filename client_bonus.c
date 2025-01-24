/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:07:12 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/24 15:15:38 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirm(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message sent successfully\n");
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (write(1, "Usage: ./client_bonus <PID> <message>\n", 38));
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID\n", 12);
		return (1);
	}
	while (av[2][i] != '\0')
	{
		send_char(pid, av[2][i]);
		i++;
	}
	signal(SIGUSR1, ft_confirm);
	send_char(pid, '\0');
}
