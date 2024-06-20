/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_formatspecs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:55:41 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:04:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	RESET_FORMATSPECS
	Resets the provided t_specs struct specs to all members switched off
	and counters to zero, except for the number of already printed tag with
	an unknown character.
	PARAMETER(S)
		The address of the t_specs struct that holds information about
		a conversion specification.
	RETURN
	-
*/

void	reset_formatspecs(t_specs *specs)
{
	specs->dash = 0;
	specs->zero = 0;
	specs->hash = 0;
	specs->blank = 0;
	specs->plus = 0;
	specs->star_width = -1;
	specs->width = 0;
	specs->star_precis = -1;
	specs->precis = -1;
	specs->specif = 0;
	specs->n_chars = 0;
}
