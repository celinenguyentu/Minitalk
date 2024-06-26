/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:23:56 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 16:40:25 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (sign * number);
}

/*	//TEST CASES
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*test_cases[] = {
		"12345",
		"-54321",
		"  6789",
		"+9876",
		"0",
		"-0",
		"2147483647",
		"-2147483648",
		"  123abc",
		"abc123",
		"123abc456",
		"",
		"   ",
		NULL
	};
	const char	**test = test_cases;

	while (*test)
	{
		printf("Input: \"%s\"\n", *test);
		printf("atoi: %d\n", atoi(*test));
		printf("ft_atoi: %d\n\n", ft_atoi(*test));
		test++;
	}
	return (0);
}
*/