/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:29:26 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_INT
	Retrieves the int argument to convert for output from the va_list args as
	well as optional arguments specifying width and precision, and prints the
	formatted argument to standart output according to the conversion
	specification provided as input.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 is an error occured.
*/

ssize_t	print_int(t_specs specs, va_list *args)
{
	ssize_t	n_chars;
	long	arg;
	int		uarg_len;
	int		sign;

	n_chars = 0;
	arg = (long)va_arg(*args, int);
	sign = (arg < 0) * -1 + (arg == 0) * 0 + (arg > 0) * 1;
	if (sign == -1)
		arg *= -1;
	uarg_len = ft_uintlen(arg, 10);
	if (arg == 0 && specs.precis == 0)
		uarg_len = 0;
	precision_overflow_handler(&specs, uarg_len);
	clean_formatspecs(&specs);
	if (!check(&n_chars, print_intprefix(specs, uarg_len, sign)))
		return (-1);
	if (arg != 0 || specs.precis != 0)
		if (!check(&n_chars, ft_putuint(arg, specs.specif)))
			return (-1);
	if (specs.dash == 1 && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}
