/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/12 22:55:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_put_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int 	idx;
	pid_t	pid;

	idx = 0;
	if (argc < 3)
		ft_put_error("Missing arguments");
	while (argv[1][idx])
		if (!ft_isdigit(argv[1][idx++]))
			ft_put_error("Invalid PID");
	if (argc > 3)
		ft_put_error("Too many arguments");
	pid = atoi(argv[1]);
	idx = 0;
	while (argv[2][idx])
	{
		if (argv[2][idx] == ' ')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		idx++;
	}
	return (EXIT_SUCCESS);
}