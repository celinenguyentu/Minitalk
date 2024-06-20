/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:12:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/20 19:28:52 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal;

void	handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_signal = info->si_pid;
	else
		g_signal = -info->si_pid;
}

int	decode_length(t_exchange *info)
{
	int		bits;
	int		timer;

	bits = 0;
	info->client = (2 * (g_signal > 0) - 1) * g_signal;
	info->length = (info->length << 1) | (g_signal < 0);
	bits++;
	g_signal = 0;
	while (bits < (int)(sizeof(size_t) * 8))
	{
		timer = 0;
		if (kill(info->client, SIGUSR1) == -1)
			return (info->error = SIGERR, SIGERR);
		while (!g_signal && timer++ < TIMEOUT)
			usleep(1);
		if (timer >= TIMEOUT)
			return (info->error = TOERR, TOERR);
		if (g_signal != info->client && g_signal != -info->client)
			return (info->error = PIDERR, PIDERR);
		info->length = (info->length << 1) | (g_signal < 0);
		bits++;
		g_signal = 0;
	}
	return (0);
}

int	alloc_data(t_exchange *info)
{
	info->data = (char *)ft_calloc(info->length + 1, sizeof(char));
	if (!info->data)
		return (info->error = MEMERR, MEMERR);
	return (0);
}

int	decode_data(t_exchange *info)
{
	unsigned char	c;
	int				bits;
	int				timer;

	while (info->idx < info->length + 1)
	{
		c = 0;
		bits = 0;
		while (bits++ < 8)
		{
			timer = 0;
			if (kill(info->client, SIGUSR1) == -1)
				return (info->error = SIGERR, SIGERR);
			while (!g_signal && timer++ < TIMEOUT)
				usleep(1);
			if (timer >= TIMEOUT)
				return (info->error = TOERR, TOERR);
			if (g_signal != info->client && g_signal != -info->client)
				return (info->error = PIDERR, PIDERR);
			c = (c << 1) | (g_signal < 0);
			g_signal = 0;
		}
		((unsigned char *)info->data)[info->idx++] = c;
	}
	return (0);
}

int	main(void)
{
	t_exchange	info;

	ft_bzero(&info, sizeof(t_exchange));
	ft_printf("Server PID : %d\nWaiting for messages ...\n\n", getpid());
	set_signal_handler(handler);
	while (1)
	{
		pause();
		if (!decode_length(&info) && !alloc_data(&info) && !decode_data(&info))
		{
			if (kill(info.client, SIGUSR1) == -1)
				info.error = SIGERR;
			else
				ft_putstr_fd(info.data, STDOUT_FILENO);
		}
		clear_exchange(&info);
	}
	return (EXIT_SUCCESS);
}
