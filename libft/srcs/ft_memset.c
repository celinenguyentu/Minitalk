/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:05:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 17:35:52 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		((unsigned char *)b)[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

void	print_bytes(const void *s, int n)
{
	printf("Memory : ");
	for (int i = 0; i < n; i++)
		printf("%d ", ((unsigned char *)s)[i]);
	printf("\n");
}

void	test(char c, size_t len)
{
	char	string1[30] = "Coucou les cocos";
	char	string2[30] = "Coucou les cocos";

	printf("Input : \"%s\"\n", string1);
	print_bytes(string1, 30);
	printf("Setting %ld '%c'\n", len, c);
	memset(string1, c, len);
	ft_memset(string2, c, len);
	printf("memset : %s\n", string1);
	print_bytes(string1, 30);
	printf("ft_memset : %s\n", string2);
	print_bytes(string2, 30);
}

int	main(void)
{
	test('A', 0);
	test('x', 5);
	test(122, 20);
	return (0);
}
*/