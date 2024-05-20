/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 03:54:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode_pid(int sigid)
{
	static char	c = 0;
	static int	bits = 0;
	static int	client_pid = 0;

	if (sigid == SIGUSR2)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		if (c == 0)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			signal(SIGUSR1, &decode_message);
			signal(SIGUSR2, &decode_message);
		}
		else
			client_pid = client_pid * 10 + (c - '0');
		bits = 0;
		c = 0;
	}
	c = c << 1;
}

void	decode_message(int sigid)
{
	static char	c = 0;
	static int	bits = 0;

	if (sigid == SIGUSR2)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		if (c == 0)
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			signal(SIGUSR1, &decode_pid);
			signal(SIGUSR2, &decode_pid);
		}
		ft_putchar_fd(c, STDOUT_FILENO);
		bits = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putstr_fd("\nReceiving messages ... \n\n", STDOUT_FILENO);
	signal(SIGUSR1, &decode_message);
	signal(SIGUSR2, &decode_message);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
