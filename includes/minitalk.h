/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:48:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 03:23:57 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isnumber(const char *str);
void	ft_puterror(char *str);
void	send_break(int pid);

// server
void	decode_message(int sigid);
void	decode_pid(int sigid);

#endif