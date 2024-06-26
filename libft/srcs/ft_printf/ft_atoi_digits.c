/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:23:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:23 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_ATOI_DIGITS
	Converts the initial portion of the string pointed to by str to int
	representation only considering digits. Unlike atoi(), the string may not
	begin with white spaces nor '+' and '-' signs.
	PARAMETER(S)
		The string holding the unsigned number in decimal base represented by
		digit characters.
	RETURN VALUE
	The function returns the result of the conversion as a long variable.
	If no conversion could be perfomed, 0 is returned. If an overflow occured,
	the function returns INT_MIN.
	EXAMPLES
		ft_atoi_digits("1234abcfd") returns 1234
		ft_atoi_digits("") returns 0
		ft_atoi_digits("-5678") returns 0
*/

long	ft_atoi_digits(const char *str)
{
	long	number;

	number = 0;
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		if (number < 0)
			return (INT_MIN);
	}
	return (number);
}
