/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:55:32 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 17:21:23 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (0);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

void	print_bytes(const void *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ((unsigned char *)s)[i]);
	}
	printf("\n");
}

void	test(const void *s1, const void *s2, size_t n)
{
	printf("Comparing memory areas :\n");
	printf("s1 = ");
	print_bytes(s1, n);
	printf("s2 = ");
	print_bytes(s2, n);
	printf("memcmp : %d\n", memcmp(s1, s2, n));
	printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, n));
}

int	main(void)
{
	char	c1[] = {-128, 0, 127, 0};
	char	c2[] = {-128, 0, 127, 0};
	char	c3[] = {0, 0, 127, 0};
	char	c4[] = {0, 0, 42, 0};

	test(c1, c2, 4);
	test(c1, c3, 0);
	test(c1, c3, 1);
	test(c3, c1, 1);
	test(c3, c4, 4);
	return (0);
}
*/