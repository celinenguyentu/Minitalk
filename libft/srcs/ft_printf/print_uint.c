/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:18:10 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:04:14 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_UINT
	Retrieves the unsigned int argument to convert for output from the va_list
	args as well as optional arguments specifying width and precision, and
	prints the formatted argument to standart output according to the conversion
	specification provided as input.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	3.	The base length used for integer conversion
	RETURN
	The number of characters printed or -1 if an error occured.
*/

ssize_t	print_uint(t_specs specs, va_list *args, int baselen)
{
	ssize_t			n_chars;
	unsigned int	arg;
	int				arg_len;

	n_chars = 0;
	arg = va_arg(*args, unsigned int);
	arg_len = ft_uintlen(arg, baselen);
	if (arg == 0 && specs.precis == 0)
		arg_len = 0;
	precision_overflow_handler(&specs, arg_len);
	clean_formatspecs(&specs);
	if (specs.specif == 'o' && specs.hash && (arg != 0 || specs.precis == 0))
		arg_len++;
	if (!check(&n_chars, print_intprefix(specs, arg_len, (arg != 0))))
		return (-1);
	if (arg != 0 || specs.precis != 0)
		if (!check(&n_chars, ft_putuint(arg, specs.specif)))
			return (-1);
	if (specs.dash == 1 && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}
