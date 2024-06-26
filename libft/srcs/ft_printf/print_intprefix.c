/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:18:52 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:03:15 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_INTPREFIX
	Prints the formatted prefix to an integer argument to the standart output
	according to the conversion specification provided as input. It handles
	left-padding, either by blanks or zeros, '-' and '+' signs and specific
	prefix given by the flag '#'.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options
	2.	The length of the integer argument to be printed excluding the 
		negative sign '-' in case of negative integer
	3.	The sign of the integer argument : -1 for negative, 0 for nul, 
		1 for positive
	RETURN
	The number of characters printed, or -1 if an error occured.
*/

static ssize_t	print_prefix(t_specs specs, int sign)
{
	ssize_t	n_chars;

	n_chars = 0;
	if (sign == -1 && !check(&n_chars, ft_putchar('-')))
		return (-1);
	if (sign > -1 && specs.blank && !check(&n_chars, ft_putchar(' ')))
		return (-1);
	if (sign > -1 && specs.plus && !check(&n_chars, ft_putchar('+')))
		return (-1);
	if (ft_strchr("xX", specs.specif) && specs.hash && sign != 0)
	{
		if (!check(&n_chars, ft_putchar('0')))
			return (-1);
		if (!check(&n_chars, ft_putchar(specs.specif)))
			return (-1);
	}
	return (n_chars);
}

ssize_t	print_intprefix(t_specs specs, int uarg_len, int sign)
{
	ssize_t	n_chars;
	ssize_t	n_zeros;
	ssize_t	offset;

	n_chars = 0;
	n_zeros = 0;
	if (specs.precis > -1 && uarg_len < specs.precis)
		n_zeros = specs.precis - uarg_len;
	offset = (sign == -1 || specs.blank || specs.plus) + uarg_len + n_zeros;
	offset += (ft_strchr("xX", specs.specif) && specs.hash && sign != 0) * 2;
	if (!specs.dash && !specs.zero && n_chars < specs.width - offset)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - offset - n_chars)))
			return (-1);
	if (!check(&n_chars, print_prefix(specs, sign)))
		return (-1);
	if (specs.specif == 'o' && specs.hash && (sign != 0 || specs.precis == 0))
		if (!check(&n_chars, ft_putchar('0')))
			return (-1);
	if (specs.zero && n_chars < specs.width - uarg_len)
		n_zeros += specs.width - uarg_len - n_chars;
	if (!check(&n_chars, ft_putnchar('0', n_zeros)))
		return (-1);
	return (n_chars);
}
