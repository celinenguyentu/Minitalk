/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:34:05 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:03:28 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_PERCENT
	Retrieves the optional arguments specifying width and precision from the
	va_list args, and prints the formatted percent symbol '%' to standart
	output according to the conversion specification provided as input.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 if an error occured.
*/

#if defined(__APPLE__)

ssize_t	print_percent(t_specs specs)
{
	ssize_t	n_chars;

	n_chars = 0;
	clean_formatspecs(&specs);
	if (!specs.dash && !specs.zero && n_chars < specs.width - 1)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - 1 - n_chars)))
			return (-1);
	if (specs.zero && n_chars < specs.width - 1)
		if (!check(&n_chars, ft_putnchar('0', specs.width - 1 - n_chars)))
			return (-1);
	if (!check(&n_chars, ft_putchar('%')))
		return (-1);
	if (specs.dash && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

ssize_t	print_percent(t_specs specs)
{
	(void)specs;
	return (ft_putchar('%'));
}

#endif