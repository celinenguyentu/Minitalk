/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:16:58 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 17:11:34 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	long	nbr;
	size_t	len;

	nbr = n;
	len = 0;
	if (n == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	size;
	char	*strnbr;
	size_t	idx;

	nbr = n;
	size = ft_nbrlen(n);
	strnbr = (char *)malloc((size + 1) * sizeof(char));
	if (!strnbr)
		return (NULL);
	idx = 0;
	if (nbr == 0)
		strnbr[0] = '0';
	if (nbr < 0)
	{
		strnbr[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		strnbr[size - idx++ - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	strnbr[size] = '\0';
	return (strnbr);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		integers[5] = {12345, -98765, 0, -2147483648, 2147483647};

	for (int i = 0; i < 5; i++)
	{
		printf("Input : %d\n", integers[i]);
		str = ft_itoa(integers[i]);
		if (!str)
			printf("Memory allocation failed.\n\n");
		else
		{
			printf("itoa : %s\n\n", str);
			free(str);
		}
	}
	return (0);
}
*/