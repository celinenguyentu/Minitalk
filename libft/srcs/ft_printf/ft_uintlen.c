/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:08:20 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_UINTLEN
	Computes the number of characters representing an unsigned integer
	converted in a specific base.
	PARAMETER(S)
	1.	The unsigned decimal integer of type unsigned long.
	2.	The base length of type int used for integer conversion.
	RETURN
	The function returns the number of characters representing the number in
	the specified base. If the base is not valid, 0 is returned.
	EXAMPLES
		ft_uintlen(42, 10) returns 2
		ft_uintlen(0, 8) returns 1
		ft_uintlen(2024, 16) returns 3
*/

size_t	ft_uintlen(unsigned long int n, int base)
{
	if (base < 2)
		return (0);
	if (n < (unsigned long int)base)
		return (1);
	else
		return (ft_uintlen(n / base, base) + ft_uintlen(n % base, base));
}
