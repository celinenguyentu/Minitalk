/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:46:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/20 04:02:41 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isnumber(const char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

void	ft_puterror(char *str, int usage)
{
	ft_putendl_fd(str, STDERR_FILENO);
	if (usage)
	{
		ft_putstr_fd("Usage : ./client <server_pid> <message>", STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	clear_exchange(t_exchange *info)
{
	if (info->error)
		info->error = -kill(info->client, SIGUSR2);
	if (info->error == SIGERR)
		ft_putendl_fd("Error: Could not ping client.", STDERR_FILENO);
	else if (info->error == PIDERR)
		ft_putendl_fd("Error: Signal from unknowm PID.", STDERR_FILENO);
	else if (info->error == MEMERR)
		ft_putendl_fd("Error: Memory allocation failed.", STDERR_FILENO);
	else if (info->error == TOERR)
		ft_putendl_fd("Error: Connection with client is lost.", STDERR_FILENO);
	info->client = 0;
	info->length = 0;
	info->error = 0;
	if (info->data)
		free(info->data);
	info->data = NULL;
	info->idx = 0;
}

void	set_signal_handler(void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	ac;

	ft_bzero(&ac, sizeof(struct sigaction));
	ac.sa_sigaction = handler;
	sigemptyset(&ac.sa_mask);
	ac.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &ac, NULL) < 0 || sigaction(SIGUSR2, &ac, NULL) < 0)
		ft_puterror("Error: Handler setup failed.", 0);
}
