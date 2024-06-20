/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/20 03:15:56 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_acknowledgement;

void	send_signal(int server_pid, int signal)
{
	int	timer;

	timer = 0;
	if (kill(server_pid, signal) == -1)
		ft_puterror("Error: Signal could not be sent.", 0);
	while (!g_acknowledgement && timer++ < TIMEOUT)
		usleep(1);
	if (timer >= TIMEOUT)
		ft_puterror("Error: Connection is lost.", 0);
	if (g_acknowledgement != server_pid && g_acknowledgement != -server_pid)
		ft_puterror("Error: Signal from unknowm PID.", 0);
	if (g_acknowledgement < 0)
		ft_puterror("Error: Server has encountered an error.", 0);
	g_acknowledgement = 0;
}

void	send_message(int server_pid, char *str)
{
	int	bits;

	while (*str)
	{
		bits = 8;
		while (bits-- > 0)
		{
			if (((*str >> bits) & 1) == 0)
				send_signal(server_pid, SIGUSR1);
			else
				send_signal(server_pid, SIGUSR2);
		}
		str++;
	}
	bits = 8;
	while (bits-- > 0)
		send_signal(server_pid, SIGUSR1);
}

void	send_length(int server_pid, char *str)
{
	size_t	len;
	int		bits;

	len = ft_strlen(str);
	bits = sizeof(size_t) * 8;
	while (bits-- > 0)
	{
		if (((len >> bits) & 1) == 0)
			send_signal(server_pid, SIGUSR1);
		else
			send_signal(server_pid, SIGUSR2);
	}
}

void	acknowledgement(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_acknowledgement = info->si_pid;
	else
		g_acknowledgement = -info->si_pid;
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;

	if (argc < 3)
		ft_puterror("Error: Missing arguments.", 1);
	if (argc > 3)
		ft_puterror("Error: Too many arguments.", 1);
	server_pid = ft_atoi(argv[1]);
	if (!ft_isnumber(argv[1]) || server_pid == 0 || kill(server_pid, 0) < 0)
		ft_puterror("Error: Invalid PID.", 1);
	set_signal_handler(acknowledgement);
	send_length(server_pid, argv[2]);
	send_message(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
