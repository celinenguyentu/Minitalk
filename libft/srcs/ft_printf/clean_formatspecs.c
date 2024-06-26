/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_formatspecs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:14:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:07 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	CLEAN_FORMATSPECS
	Switch off the flags that are not applicable to the conversion specification
	represented by specs according to overriding rules and conversion specifiers.
	PARAMETER(S)
		The address of the t_specs struct that holds information about
		a conversion specification.
	RETURN VALUE
	-
*/

void	clean_formatspecs(t_specs *specs)
{
	if (specs->dash == 1 && specs->zero == 1)
		specs->zero = 0;
	if (specs->plus == 1 && specs->blank == 1)
		specs->blank = 0;
	if (specs->specif && ft_strchr(SPECIFIERS, specs->specif))
	{
		if (!ft_strchr("xXo", specs->specif))
			specs->hash = 0;
		if (!ft_strchr("pdi", specs->specif))
		{
			specs->blank = 0;
			specs->plus = 0;
		}
		if (ft_strchr("diuxXo", specs->specif) && specs->precis > -1)
			specs->zero = 0;
	}
}
