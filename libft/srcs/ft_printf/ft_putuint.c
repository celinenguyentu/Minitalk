/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:00:12 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTUINT
	Writes the unsigned decimal integer n to the standard output stream. The
	integer is converted to the base specified before printing.
	PARAMETER(S)
	1.	The unsigned decimal integer of type unsigned long to be printed.
	2.	The base of type int representing a char in which to print the integer.
		- 'd', 'i', 'u' : decimal base
		- 'x', 'X' : hexadecimal base with resp. lower and upper case letters
		- 'o' : octal base
		Any other base is undefined behaviour.
	RETURN
	The function returns the number of characters printed representing the
	number in the specified base. If an error occured, it returns -1.
	EXAMPLES
		ft_putuint(42, 'i') outputs "42" and returns 2
		ft_putuint(0, 'o') outputs "0" and returns 1
		ft_putuint(2024, 'x') outputs "7e8" and returns 3
*/

static void	fill_uint(char *buf, unsigned long n, int base, size_t uintlen);

static void	fill_callback(char *buf, unsigned long n, int base, size_t uintlen)
{
	int	operand;

	if (base == 'x' || base == 'X')
		operand = 16;
	else if (base == 'o')
		operand = 8;
	else
		operand = 10;
	fill_uint(buf, n / operand, base, uintlen);
	fill_uint(buf, n % operand, base, uintlen);
}

static void	fill_uint(char *buf, unsigned long n, int base, size_t uintlen)
{
	static size_t	idx = 0;

	if (base == 'x' && n < 16)
		buf[idx++] = LOWHEXADECIMAL[n];
	else if (base == 'X' && n < 16)
		buf[idx++] = UPHEXADECIMAL[n];
	else if (base == 'o' && n < 8)
		buf[idx++] = OCTAL[n];
	else if (base && ft_strchr("diu", base) && n < 10)
		buf[idx++] = DECIMAL[n];
	else if (base == 'x')
		fill_callback(buf, n, base, uintlen);
	else if (base == 'X')
		fill_callback(buf, n, base, uintlen);
	else if (base == 'o')
		fill_callback(buf, n, base, uintlen);
	else if (base && ft_strchr("diu", base))
		fill_callback(buf, n, base, uintlen);
	if (idx == uintlen)
		idx = 0;
}

ssize_t	ft_putuint(unsigned long int n, int base)
{
	char	*buf;
	ssize_t	bytes_written;
	size_t	uintlen;

	if (base == 'x' || base == 'X')
		uintlen = ft_uintlen(n, 16);
	else if (base == 'o')
		uintlen = ft_uintlen(n, 8);
	else
		uintlen = ft_uintlen(n, 10);
	buf = (char *)malloc(uintlen * sizeof(char));
	if (!buf)
		return (-1);
	bytes_written = 0;
	fill_uint(buf, n, base, uintlen);
	bytes_written = write(STDOUT_FILENO, buf, uintlen);
	free(buf);
	return (bytes_written);
}
