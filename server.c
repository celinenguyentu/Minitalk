/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/12 22:58:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sigid)
{
	if (sigid == SIGUSR1)
		write(1, "0", 1);
	if (sigid == SIGUSR2)
		write(1, "1", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID : %d\n\n", pid);
	printf("Receiving messages...\n");
	signal(SIGUSR1, &handler); // exit on error
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}