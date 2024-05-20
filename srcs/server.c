/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 03:24:13 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			ft_putchar_fd('\n', STDOUT_FILENO);
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
	ft_putstr_fd("\nWaiting for messages ... \n\n", STDOUT_FILENO);
	signal(SIGUSR1, &decode_message);
	signal(SIGUSR2, &decode_message);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
