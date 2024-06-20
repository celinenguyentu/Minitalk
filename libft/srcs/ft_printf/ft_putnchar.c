/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:33:25 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:43 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTNCHAR
	Writes n consecutive characters c to the standard output stream.
	PARAMETER(S)
	1.	The character c of type char to be printed.
	2.	The number of occurences of c to be printed.
	RETURN
	The function returns the number of bytes written in stdout.
	If an error occured, it returns -1.
*/

ssize_t	ft_putnchar(unsigned char c, ssize_t n)
{
	char	*output;
	ssize_t	total_bytes_written;
	ssize_t	bytes_written;

	if (n <= 0)
		return (0);
	output = (char *)malloc(n * sizeof(char));
	if (!output)
		return (-1);
	ft_memset(output, c, n);
	bytes_written = write(STDOUT_FILENO, output, n);
	total_bytes_written = bytes_written;
	while (bytes_written != -1 && bytes_written < n)
	{
		n -= bytes_written;
		bytes_written = write(STDOUT_FILENO, output, n);
		if (bytes_written == -1)
			total_bytes_written = bytes_written;
		else
			total_bytes_written += bytes_written;
	}
	free(output);
	return (total_bytes_written);
}
