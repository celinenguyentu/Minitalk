/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_overflow_handler.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:50:57 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:29 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRECISION_OVERFLOW_HANDLER
	Changes precision to none when an overflow error occurs.
	PARAMETER(S)
	1.	The initial precision
	2.	The length of the argument that should be printed.
	RETURN VALUE
	The function returns the new precision after overflow check.
*/

void	precision_overflow_handler(t_specs *specs, int arg_len)
{
	if (specs->precis > INT_MAX && specs->precis - arg_len > INT_MAX)
		specs->precis = -1;
	else if (specs->precis < 0 && specs->precis > (long)INT_MIN - 1)
	{
		if (specs->precis - arg_len >= INT_MIN)
			specs->precis = -1;
		else
			specs->precis = -((long)INT_MIN - (specs->precis - (long)INT_MIN));
	}
}
