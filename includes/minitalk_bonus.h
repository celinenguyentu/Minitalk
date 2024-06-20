/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:48:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/20 20:20:31 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

# define SIGERR 1
# define PIDERR 2
# define MEMERR 3
# define TOERR 4
# define TIMEOUT 10000

typedef struct s_exchange
{
	pid_t	client;
	size_t	length;
	char	*data;
	size_t	idx;
	int		error;
}	t_exchange;

int		ft_isnumber(const char *str);
void	ft_puterror(char *str, int usage);
void	clear_exchange(t_exchange *info);
void	set_signal_handler(void (*handler)(int, siginfo_t *, void *));

#endif