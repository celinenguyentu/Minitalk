/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 21:59:24 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
	FT_PRINTF
	Formats and prints in the standard ouput its arguments, after the first,
	under control of the string format. The format string may contain format
	specifications, each of which causes printing of the next successive
	argument. Each format specification is introduced by the percent character
	'%' followed by, in the following order :
	- Zero or more flags among the following : "#0- +"
	- An optional digit string specifying a field width
	- An optional period '.' followed by an optional digit string giving a 
	precision.
	- A format specifier of type char which indicates the type of format to use
	among the following : "cspdiuxX%o"
	A field width or precision may be ‘*’ instead of a digit string. In this
	case an argument supplies the field width or precision.
	PARAMETER(S)
	1.	The format string to control the output
	2.	A variable number of arguments used and converted for output
	RETURN
	The function returns the number of characters printed in the standard
	output, excluding the null-terminating '\0' character of the format string.
	In case of error, it returns -1.
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n_chars;

	va_start(ap, format);
	n_chars = ft_vprintf(format, ap);
	va_end(ap);
	return (n_chars);
}
