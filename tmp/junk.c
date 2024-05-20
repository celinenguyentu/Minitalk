/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 05:22:20 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 05:22:30 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bit_message(int sigid)
{
	static char	c = 0;
	static int	bits = 0;

	//if (sigid == SIGUSR1)
	//	write(1, "0", 1);
	if (sigid == SIGUSR2)
	{
	//	write(1, "1", 1);
		c = c | 1;
	}
	bits++;
	if (bits == 8)
	{
		//ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putchar_fd(c, STDOUT_FILENO);
		//ft_putchar_fd('\n', STDOUT_FILENO);
		bits = 0;
		c = 0;
	}
	c = c << 1;
}