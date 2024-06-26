/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:48:42 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:03 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_STRDLEN
	Finds length of the initial portion of the string pointed to by str that
	is fully constituted of digit characters.
	PARAMETER(S)
		The string holding the unsigned number in decimal base represented by
		digit characters.
	RETURN
	The function returns the number of digits at the beginning the string. 
	If the string is empty or starts with non-digit characters, 0 is returned.
	EXAMPLES
		ft_strdlen("1234abcfd") returns 4
		ft_strdlen("") returns 0
		ft_strdlen("-5678") returns 0
*/

int	ft_strdlen(const char *str)
{
	int	count;

	count = 0;
	while (ft_isdigit(*str))
	{
		count++;
		str++;
	}
	return (count);
}
