/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_formatspecs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:40:16 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:23 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	INIT_FORMATSPECS
	Initializes the provided t_specs struct specs to all members switched off
	and counters to zero.
	PARAMETER(S)
		The address of the t_specs struct that holds information about
		a conversion specification.
	RETURN
	-
*/

void	init_formatspecs(t_specs *specs)
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
	specs->n_unknowns = 0;
}
