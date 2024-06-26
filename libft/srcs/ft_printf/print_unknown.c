/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:14:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:04:31 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_UNKNOWN
	Retrieves the optional arguments specifying width and precision from the
	va_list args, and prints the formatted regular character stored as unknown
	specifier to standart output according to the conversion specification
	provided as input.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 if an error occured.
*/

#if defined(__APPLE__)

ssize_t	print_unknown(t_specs specs)
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
	if (!check(&n_chars, ft_putchar(specs.specif)))
		return (-1);
	if (specs.dash && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

static ssize_t	print_flags(t_specs specs)
{
	ssize_t	n_chars;
	char	*buffer;
	size_t	idx;

	n_chars = specs.hash + specs.plus + specs.blank + specs.dash + specs.zero;
	buffer = (char *)malloc((n_chars + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	idx = 0;
	buffer[idx++] = '%';
	if (specs.hash)
		buffer[idx++] = '#';
	if (specs.plus)
		buffer[idx++] = '+';
	if (specs.blank)
		buffer[idx++] = ' ';
	if (specs.dash)
		buffer[idx++] = '-';
	if (specs.zero)
		buffer[idx++] = '0';
	n_chars = write(STDOUT_FILENO, buffer, idx);
	free(buffer);
	return (n_chars);
}

ssize_t	print_unknown(t_specs specs)
{
	ssize_t	n_chars;

	n_chars = 0;
	if (!check(&n_chars, print_flags(specs)))
		return (-1);
	if (specs.width)
		if (!check(&n_chars, ft_putuint(specs.width, 'i')))
			return (-1);
	if (specs.precis > -1)
	{
		if (!check(&n_chars, ft_putchar('.')))
			return (-1);
		if (!check(&n_chars, ft_putuint(specs.precis, 'i')))
			return (-1);
	}
	if (specs.specif != '\0')
		if (!check(&n_chars, ft_putchar(specs.specif)))
			return (-1);
	return (n_chars);
}

/* TIME OPTIMIZATION (write only once)
ssize_t	print_unknown(t_specs specs, va_list *args)
{
	ssize_t	n_chars;
	char	*buffer;
	char	*number;
	size_t	idx;

	n_chars = 1 + (specs.specif);
	n_chars += specs.hash + specs.plus + specs.blank + specs.dash + specs.zero;
	if (specs.width)
		n_chars += ft_uintlen(specs.width, 10);
	if (specs.precis > -1)
		n_chars += 1 + ft_uintlen(specs.precis, 10);
	buffer = (char *)malloc(n_chars * sizeof(char));
	if (!buffer)
		return (-1);
	idx = 0;
	number = ft_itoa(specs.width);
	buffer[idx++] = '%';
	if (specs.hash)
		buffer[idx++] = '#';
	if (specs.plus)
		buffer[idx++] = '+';
	if (specs.blank)
		buffer[idx++] = ' ';
	if (specs.dash)
		buffer[idx++] = '-';
	if (specs.zero)
		buffer[idx++] = '0';
	if (specs.width)
	{
		if (!ft_memcpy(buffer + idx, number, ft_strlen(number)))
		{
			free(number);
			free(buffer);
			return (-1);
		}
		idx += ft_strlen(number);
	}
	free(number);
	number = ft_itoa(specs.precis);
	if (specs.precis > -1)
	{
		buffer[idx++] = '.';
		if (!ft_memcpy(buffer + idx, number, ft_strlen(number)))
		{
			free(number);
			free(buffer);
			return (-1);
		}
		idx += ft_strlen(number);
	}
	free(number);
	if (specs.specif)
		buffer[idx++] = specs.specif;
	n_chars = write(STDOUT_FILENO, buffer, idx);
	free(buffer);
	return (n_chars);
}
*/

#endif
