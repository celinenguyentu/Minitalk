/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:54:34 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:48 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTNSTR
	Writes n consecutive characters of a string to the standard output stream.
	PARAMETER(S)
	1.	The string str of type char * to be printed.
	2.	The number of characters from str to be printed.
	RETURN
	The function returns the number of bytes written in stdout.
	If an error occured, it returns -1.
*/

ssize_t	ft_putnstr(const char *str, size_t n)
{
	size_t	strlen;
	ssize_t	bytes_written;

	strlen = ft_strlen(str);
	bytes_written = 0;
	if (strlen < n)
		bytes_written = write(STDOUT_FILENO, str, strlen);
	else
		bytes_written = write(STDOUT_FILENO, str, n);
	return (bytes_written);
}
