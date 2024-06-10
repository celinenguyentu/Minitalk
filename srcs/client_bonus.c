/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/10 05:19:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int server_pid, char *str)
{
	int	bits;
	int	bit;

	while (*str)
	{
		bits = 8;
		while (bits-- > 0)
		{
			bit = (*str >> bits) & 1;
			if (bit == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(200);
		}
		str++;
	}
	bits = 8;
	while (bits-- > 0)
	{
		kill(server_pid, SIGUSR1);
		usleep(200);
	}
}

void	send_client_pid(int server_pid, int client_pid)
{
	char	digit;
	int		bits;
	int		bit;

	if (client_pid > 10)
		send_client_pid(server_pid, client_pid / 10);
	digit = (client_pid % 10) + '0';
	bits = 8;
	while (bits-- > 0)
	{
		bit = (digit >> bits) & 1;
		if (bit == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);
	}
}

void	message_received(int sigid)
{
	(void)sigid;
	ft_putstr_fd("Your message has been received.\n", STDOUT_FILENO);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	pid_t	client_pid;

	if (argc < 3)
		ft_puterror("Missing arguments.\n");
	if (argc > 3)
		ft_puterror("Too many arguments.\n");
	if (!ft_isnumber(argv[1]))
		ft_puterror("Invalid PID.\n");
	signal(SIGUSR1, &message_received);
	signal(SIGUSR2, &message_received);
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	client_pid = getpid();
	send_client_pid(server_pid, client_pid);
	send_break(server_pid);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
