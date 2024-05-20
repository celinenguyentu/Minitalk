/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:50:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/05 14:16:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*	//TEST CASES
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("char\tprint\tisdigit\tft_isdigit\n");
	for (int i = 0; i <= 255; i++)
	{
		printf("%d\t", i);
		if (ft_isprint(i))
			printf("%c\t", i);
		else
			printf("-\t");
		printf("%d\t", isdigit(i));
		printf("%d\n", ft_isdigit(i));
	}
	return (0);
}
*/