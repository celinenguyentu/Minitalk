/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/10 05:12:30 by cnguyen-         ###   ########.fr       */
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
			usleep(210);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc < 3)
		ft_puterror("Missing arguments.\n");
	if (argc > 3)
		ft_puterror("Too many arguments.\n");
	if (!ft_isnumber(argv[1]))
		ft_puterror("Invalid PID.\n");
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	send_break(server_pid);
	return (EXIT_SUCCESS);
}
