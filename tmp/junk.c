/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 05:22:20 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/20 02:29:42 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SERVER works
// too many globals
// volatile ? sig_atomic ? block signals ? SA_RESTART ? 

#define M_MESS 1
#define M_LEN -1
typedef struct s_message
{
	size_t	length;
	char	*data;
	int		mode;
	int		error;
	pid_t	client;
}	t_message;

void	switch_handler(void);

volatile t_message	g_comm;

void	decode_message(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		bits;
	static size_t	idx;

	(void)context;
	if (g_comm.client != info->si_pid)
	{
		g_comm.error = PIDERR;
		return ;
	}
	c = (c << 1) | (signal == SIGUSR2);
	if (++bits == 8)
	{
		g_comm.data[idx++] = c;
		bits = 0;
		c = 0;
	}
	if (idx == g_comm.length + 1)
	{
		idx = 0;
		switch_handler();
	}
	else if (kill(info->si_pid, SIGUSR1) == -1)
		g_comm.error = SIGERR;
}

void	decode_length(int signal, siginfo_t *info, void *context)
{
	static size_t	len;
	static int		bits;

	(void)context;
	if (g_comm.client == 0)
		g_comm.client = info->si_pid;
	else if (g_comm.client != info->si_pid)
	{
		g_comm.error = PIDERR;
		return ;
	}
	len = (len << 1) | (signal == SIGUSR2);
	bits++;
	if (bits == sizeof(size_t) * 8)
	{
		g_comm.length = len;
		bits = 0;
		len = 0;
		switch_handler();
	}
	else if (kill(info->si_pid, SIGUSR1) == -1)
		g_comm.error = SIGERR;
}

void	switch_handler(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	if (g_comm.mode == 0 || g_comm.mode == M_MESS)
		act.sa_sigaction = decode_length;
	else
		act.sa_sigaction = decode_message;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		g_comm.error = HNDLERR;
	if (g_comm.mode == 0 || g_comm.mode == M_MESS)
		g_comm.mode = M_LEN;
	else
		g_comm.mode = M_MESS;
}

void	clear_message(void)
{
	if (!g_comm.error)
		return ;
	if (g_comm.error != ENDERR)
		g_comm.error = kill(g_comm.client, SIGUSR2);
	if (g_comm.error == SIGERR || g_comm.error == ENDERR + 1)
		ft_putendl_fd("Error: Could not ping client.", STDERR_FILENO);
	else if (g_comm.error == PIDERR)
		ft_putendl_fd("Error: Signal from unknowm PID.", STDERR_FILENO);
	else if (g_comm.error == HNDLERR)
		ft_putendl_fd("Error: Could not switch handler.", STDERR_FILENO);
	else if (g_comm.error == MEMERR)
		ft_putendl_fd("Error: Memory allocation failed.", STDERR_FILENO);
	g_comm.client = 0;
	g_comm.length = 0;
	g_comm.mode = M_LEN;
	g_comm.error = 0;
	if (g_comm.data)
		free(g_comm.data);
	g_comm.data = NULL;
}

int	main(void)
{
	ft_printf("Server PID : %d\nWaiting for messages ...\n\n", getpid());
	switch_handler();
	while (1)
	{
		pause();
		if (!g_comm.error && g_comm.mode == M_MESS && g_comm.data == NULL)
		{
			g_comm.data = (char *)malloc((g_comm.length + 1) * sizeof(char));
			if (!g_comm.data)
				g_comm.error = MEMERR;
			else
			{
				ft_bzero(g_comm.data, g_comm.length + 1);
				g_comm.error = -kill(g_comm.client, SIGUSR1);
			}
		}
		else if (!g_comm.error && g_comm.mode == M_LEN && g_comm.data != NULL)
		{
			ft_putstr_fd(g_comm.data, STDOUT_FILENO);
			g_comm.error = -kill(g_comm.client, SIGUSR1);
			g_comm.error += ENDERR;
		}
		clear_message();
	}
	return (EXIT_SUCCESS);
}
*/

/*	// SERVER
// works but has non asyn-safe functions in handlers 

void	switch_handler(void);

volatile size_t	g_message_length; // block signals ?

void	decode_message(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		bits;
	static char		*message;
	static size_t	idx;

	(void)context;
	if (!message)
		message = (char *)malloc((g_message_length + 1) * sizeof(char));
	if (!message)
		ft_puterror("Memory allocation error.\n");
	if (signal == SIGUSR2)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		message[idx++] = c;
		if (idx == g_message_length)
		{
			message[idx] = '\0';
			ft_putendl_fd(message, STDOUT_FILENO);
			free(message);
			message = NULL;
			g_message_length = 0;
			idx = 0;
			switch_handler();
		}
		bits = 0;
		c = 0;
	}
	c = c << 1;
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		if (message)
			free(message);
		ft_puterror("Failed sending signal.\n");
	}
}

void	decode_length(int signal, siginfo_t *info, void *context)
{
	static size_t	len;
	static int		bits;

	(void)context;
	if (signal == SIGUSR2)
		len = len | 1;
	bits++;
	if (bits == sizeof(size_t) * 8)
	{
		g_message_length = len;
		bits = 0;
		len = 0;
		switch_handler();
	}
	len = len << 1;
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_puterror("Failed sending signal.\n");
}

void	switch_handler(void)
{
	struct sigaction	act;
	struct sigaction	oldact;

	ft_bzero(&act, sizeof(act));
	if (sigaction(SIGUSR1, NULL, &oldact) == -1)
		ft_puterror("Failed catching current handler.\n");
	if (oldact.sa_sigaction == NULL || oldact.sa_sigaction == &decode_message)
		act.sa_sigaction = decode_length;
	else
		act.sa_sigaction = decode_message;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		ft_puterror("Error setting up handler.\n");
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc > 1)
		ft_puterror("This program does not take any argument.\n");
	(void)argv;
	server_pid = getpid();
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putstr_fd("\nWaiting for messages ... \n\n", STDOUT_FILENO);
	switch_handler();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
*/

/*	// CLIENT
// does not work
// tried to send signals from the handler

char	*message;
sig_atomic_t	server_pid;

void	send_signal(int server_pid, int signal)
{
	if (kill(server_pid, signal) == -1)
		ft_puterror("Error : Signal could not be sent.", 0);
}

void	send_message(int signal)
{
	static size_t			len = ft_strlen(message);
	static int		len_bits = sizeof(size_t) * 8;
	static int		mess_bits = 8;

	//if (signal == SIGUSR2)
	//	ft_puterror("Error : Server has encountered an error.", 0);
	(void)signal;
	if (len_bits-- > 0)
	{
		if (((len >> len_bits) & 1) == 0)
			send_signal(server_pid, SIGUSR1);
		else
			send_signal(server_pid, SIGUSR2);
	}
	else
	{
		if (mess_bits == 0)
		{
			mess_bits = 8;
			message++;
		}
		if (*message)
		{
			if (((*message >> mess_bits--) & 1) == 0)
				send_signal(server_pid, SIGUSR1);
			else
				send_signal(server_pid, SIGUSR2);
		}
		else
			exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	action;

	if (argc < 3)
		ft_puterror("Error : Missing arguments.", 1);
	if (argc > 3)
		ft_puterror("Error : Too many arguments.", 1);
	server_pid = ft_atoi(argv[1]);
	if (!ft_isnumber(argv[1]) || server_pid == 0 || kill(server_pid, 0) < 0)
		ft_puterror("Error : Invalid PID.\n", 1);
	message = argv[2];
	ft_bzero(&action, sizeof(action));
	action.sa_handler = send_message;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_puterror("Error : Handler setup failed.", 0);
	kill(getpid(), SIGUSR1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
*/

/* SERVER works
// prints char by char no optimization with handshake

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
*/

/* CLIENT works
// no optimization with handshake
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int	main(void)
{
	struct sigaction action;

	sigaction(SIGUSR1, NULL, &action);
	if (action.sa_handler == NULL)
		printf("NULL\n");
}