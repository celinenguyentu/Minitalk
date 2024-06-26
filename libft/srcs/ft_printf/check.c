/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:52:38 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:00:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	CHECK
	Detects a write error or an overflow of printed characters, and updates the
	latter accordingly.
	PARAMETER(S)
	1.	The address of the number of characters already printed before the
		last call of write.
	2.	The number of bytes printed by the last call of write.
	RETURN VALUE
	The function returns 1 and updates the number of characters printed if
	there's no error. Otherwise, it returns -1.
*/

int	check(ssize_t *n_chars, ssize_t bytes_written)
{
	if (bytes_written == -1)
		return (0);
	*n_chars += bytes_written;
	if (*n_chars < 0)
		return (0);
	return (1);
}
