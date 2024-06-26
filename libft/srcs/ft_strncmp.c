/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 03:47:08 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 18:52:50 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

void	test(const char *str1, const char *str2, int n)
{
	printf("%s vs %s (%d characters)\n", str1, str2, n);
	printf("strncmp : %d\n", strncmp(str1, str2, n));
	printf("ft_strncmp : %d\n\n", ft_strncmp(str1, str2, n));
}

int	main(void)
{
	test("apple", "apple", 6);
	test("apple", "apples", 5);
	test("apple", "apples", 6);
	test("apple", "42", 1);
	test("programming", "programmers", 8);
	test("programming", "programmers", 9);
	test("\200", "\0", 1);
	test("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 6);
	return (0);
}
*/