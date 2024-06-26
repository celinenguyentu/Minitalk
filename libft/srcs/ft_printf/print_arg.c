/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:41 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_ARG
	For each conversion specification, this function calls the appropriate
	conversion function to print the next argument from the va_list args, and
	captures the number of characters printed that it returns after checking
	for any integer overflow.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	3.	The number of characters already printed before the new argument.
	RETURN
	The total number of characters printed including the previous ones. If an
	error occured, it returns -1.
*/

int	print_arg(t_specs specs, va_list *args, int n_chars)
{
	ssize_t	bytes_written;

	if (specs.specif == 'c')
		bytes_written = print_char(specs, args);
	else if (specs.specif == 's')
		bytes_written = print_str(specs, args);
	else if (specs.specif == 'p')
		bytes_written = print_ptr(specs, args);
	else if (specs.specif == 'd' || specs.specif == 'i')
		bytes_written = print_int(specs, args);
	else if (specs.specif == 'u')
		bytes_written = print_uint(specs, args, 10);
	else if (specs.specif == 'x' || specs.specif == 'X')
		bytes_written = print_uint(specs, args, 16);
	else if (specs.specif == '%')
		bytes_written = print_percent(specs);
	else if (specs.specif == 'o')
		bytes_written = print_uint(specs, args, 8);
	else
		bytes_written = print_unknown(specs);
	if (bytes_written == -1)
		return (-1);
	if (bytes_written > INT_MAX || bytes_written + n_chars > INT_MAX)
		return (-1);
	return (bytes_written + n_chars);
}
