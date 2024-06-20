/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:44 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 21:59:44 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
	FT_VPRINTF
	The function ft_vprintf() is equivalent to the function ft_printf() except
	that it is called with a va_list instead of a variable number of arguments.
	PARAMETER(S)
	1.	The format string to control the output
	2.	The va_list storing the variable-length list of arguments used and
		converted for output
	RETURN
	The function returns the number of characters printed in the standard
	output, excluding the null-terminating '\0' character of the format string.
	In case of error or overflow, it returns -1.
*/

static int	put_text(const char **format, int n_chars)
{
	size_t		len;
	ssize_t		bytes_written;

	len = 0;
	bytes_written = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	bytes_written = write(1, *format, len);
	if (bytes_written == -1)
		return (-1);
	if (n_chars + len > INT_MAX)
		return (-1);
	*format += len;
	return (n_chars + len);
}

#if defined(__APPLE__)

static int	check_formatspecs_error(t_specs *specs, int n_chars)
{
	if (specs->width < 0 || specs->width + n_chars >= INT_MAX)
		return (1);
	if (specs->width + n_chars < 0)
		return (1);
	if (specs->star_precis == -1 && specs->precis < -1)
		return (1);
	if (ft_strchr("pdiuxXo", specs->specif) && specs->precis > 0
		&& specs->precis <= INT_MAX && specs->precis + n_chars >= INT_MAX)
		return (1);
	if (ft_strchr("pdiuxXo", specs->specif) && specs->star_precis == 0
		&& specs->precis <= (long)INT_MIN - 1)
	{
		if (specs->precis + n_chars >= (long)INT_MIN - 1)
			return (1);
		specs->precis = (int)specs->precis + n_chars;
	}
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;
	va_list	ap_;

	n_chars = 0;
	init_formatspecs(&specs);
	va_copy(ap_, ap);
	while (*format)
	{
		if (*format == '%')
		{
			update_formatspecs(&specs, &format, &ap_);
			if (check_formatspecs_error(&specs, n_chars))
				return (-1);
			if (specs.specif == '\0')
				return (n_chars);
			n_chars = print_arg(specs, &ap_, n_chars);
		}
		else
			n_chars = put_text(&format, n_chars);
		if (n_chars < 0)
			return (-1);
	}
	va_end(ap_);
	return (n_chars);
}

#else

static int	check_formatspecs_error(t_specs *specs)
{
	if (specs->width < 0)
		return (1);
	if (specs->star_precis == 0 && specs->precis < 0)
		specs->precis = -1;
	if (specs->precis < -1)
		return (1);
	if (ft_strchr("spdiuxXo", specs->specif) && specs->precis > INT_MAX)
		return (1);
	if (specs->specif && !ft_strchr(SPECIFIERS, specs->specif))
		(specs->n_unknowns)++;
	if (!specs->specif && specs->n_unknowns == 0)
		return (1);
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		n_chars;
	t_specs	specs;
	va_list	ap_;

	n_chars = 0;
	init_formatspecs(&specs);
	va_copy(ap_, ap);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			update_formatspecs(&specs, &format, &ap_);
			if (check_formatspecs_error(&specs))
				return (-1);
			n_chars = print_arg(specs, &ap_, n_chars);
		}
		else
			n_chars = put_text(&format, n_chars);
		if (n_chars < 0)
			return (-1);
	}
	va_end(ap_);
	return (n_chars);
}

#endif
