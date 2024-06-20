/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_formatspecs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 05:33:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:04:49 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	UPDATE_FORMATSPECS
	Parses the initial portion of the format string from the percent symbol '%'
	to either a specifier or an unknown character, including optional flags,
	width and precision. It stores the conversion specifications into a struct
	specs including any options like flag, width, precision, the conversion
	specifier or the next regular character if the specifier is missing, and
	the number of characters read by the parser. The invalid flags are switched
	off by the function clean_formatspec().
	PARAMETER(S)
		The format string to control the output starting at the '%' symbol
	RETURN
	The function returns the t_specs struct that holds the information of the
	conversion specification and the number of characters read from format.
*/

static const char	*read_flags(const char *frmt, t_specs *spcs)
{
	char	flag;

	while (*frmt && ft_strchr(FLAGS, *frmt))
	{
		flag = *ft_strchr(FLAGS, *frmt);
		if (flag == '-')
			spcs->dash = 1;
		else if (flag == '0')
			spcs->zero = 1;
		else if (flag == '#')
			spcs->hash = 1;
		else if (flag == ' ')
			spcs->blank = 1;
		else
			spcs->plus = 1;
		frmt++;
		spcs->n_chars += 1;
	}
	return (frmt);
}

static const char	*read_width(const char *frmt, t_specs *spcs, va_list *ap)
{
	if (*frmt == '*')
	{
		spcs->star_width = 0;
		spcs->n_chars += 1;
		frmt++;
		spcs->width = va_arg(*ap, int);
		if (spcs->width < 0)
		{
			spcs->width = -spcs->width;
			spcs->dash = 1;
		}
	}
	else if (ft_isdigit(*frmt))
	{
		spcs->width = (int)ft_atoi_digits(frmt);
		spcs->n_chars += ft_strdlen(frmt);
		frmt += ft_strdlen(frmt);
	}
	return (frmt);
}

static const char	*read_precis(const char *frmt, t_specs *spcs, va_list *ap)
{
	if (*frmt == '.')
	{
		spcs->n_chars += 1;
		if (*++frmt == '*')
		{
			spcs->star_precis = 0;
			spcs->n_chars += 1;
			frmt++;
			spcs->precis = (long)va_arg(*ap, int);
		}
		else
		{
			spcs->precis = ft_atoi_digits(frmt);
			spcs->n_chars += ft_strdlen(frmt);
			frmt += ft_strdlen(frmt);
		}
	}
	return (frmt);
}

#if defined(__APPLE__)

void	update_formatspecs(t_specs *specs, const char **format, va_list *args)
{
	reset_formatspecs(specs);
	(*format)++;
	while (**format && (ft_strchr(SYMBOLS, **format) || ft_isdigit(**format)))
	{
		*format = read_flags(*format, specs);
		*format = read_width(*format, specs, args);
		*format = read_precis(*format, specs, args);
	}
	if (**format)
	{
		specs->specif = **format;
		specs->n_chars += 1;
		(*format)++;
	}
}

#else

void	update_formatspecs(t_specs *specs, const char **format, va_list *args)
{
	reset_formatspecs(specs);
	(*format)++;
	*format = read_flags(*format, specs);
	clean_formatspecs(specs);
	*format = read_width(*format, specs, args);
	*format = read_precis(*format, specs, args);
	if (**format)
	{
		specs->specif = **format;
		specs->n_chars += 1;
		(*format)++;
	}
}

#endif
