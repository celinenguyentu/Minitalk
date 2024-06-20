/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:40:49 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:03:49 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	PRINT_PTR
	Retrieves the pointer argument to convert for output from the va_list args
	as well as optional arguments specifying width and precision, and prints
	the formatted argument to standart output according to the conversion
	specification provided as input.
	PARAMETER(S)
	1.	The t_specs struct that holds information about a conversion 
		specification, including the specifier and options.
	2.	The address of the va_list storing the variable-length list of arguments
		passed to ft_printf.
	RETURN
	The number of characters printed or -1 if an error occured.
*/

static void	switch_to_x(t_specs *specs)
{
	specs->hash = 1;
	specs->specif = 'x';
	if (specs->precis > -1)
		specs->zero = 0;
}

#if defined(__APPLE__)

ssize_t	print_ptr(t_specs specs, va_list *args)
{
	ssize_t		n_chars;
	uintptr_t	arg;
	int			arg_len;

	n_chars = 0;
	arg = (unsigned long int)va_arg(*args, void *);
	arg_len = ft_uintlen(arg, 16);
	if (arg == 0 && specs.precis == 0)
		arg_len = 0;
	precision_overflow_handler(&specs, arg_len);
	clean_formatspecs(&specs);
	switch_to_x(&specs);
	specs.blank = 0;
	specs.plus = 0;
	if (!check(&n_chars, print_intprefix(specs, arg_len, 1)))
		return (-1);
	if (arg || specs.precis != 0)
		if (!check(&n_chars, ft_putuint(arg, 'x')))
			return (-1);
	if (specs.dash == 1 && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#else

static ssize_t	print_nullptr(t_specs specs)
{
	ssize_t	n_chars;

	n_chars = 0;
	if (specs.dash == 0 && specs.width - 5 > 0)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - 5)))
			return (-1);
	if (!check(&n_chars, ft_putnstr("(nil)", 5)))
		return (-1);
	return (n_chars);
}

static ssize_t	ptr_special_case(void)
{
	ssize_t	n_chars;

	n_chars = 0;
	if (!check(&n_chars, ft_putnchar(' ', INT_MAX)))
		return (-1);
	if (!check(&n_chars, ft_putchar('0')))
		return (-1);
	return (n_chars);
}

ssize_t	print_ptr(t_specs specs, va_list *args)
{
	ssize_t		n_chars;
	uintptr_t	arg;

	n_chars = 0;
	clean_formatspecs(&specs);
	arg = (unsigned long int)va_arg(*args, void *);
	if (specs.precis == INT_MAX)
		return (ptr_special_case());
	if (arg)
	{
		switch_to_x(&specs);
		if (!check(&n_chars, print_intprefix(specs, ft_uintlen(arg, 16), 1)))
			return (-1);
		if (!check(&n_chars, ft_putuint(arg, 'x')))
			return (-1);
	}
	else
		if (!check(&n_chars, print_nullptr(specs)))
			return (-1);
	if (specs.dash == 1 && n_chars < specs.width)
		if (!check(&n_chars, ft_putnchar(' ', specs.width - n_chars)))
			return (-1);
	return (n_chars);
}

#endif
