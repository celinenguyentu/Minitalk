/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:43:38 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 16:46:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
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

void	test(size_t len)
{
	char	string1[30] = "Coucou les cocos";
	char	string2[30] = "Coucou les cocos";

	printf("Input : \"%s\"\n", string1);
	print_bytes(string1, 30);
	printf("Setting %ld zeros\n", len);
	bzero(string1, len);
	ft_bzero(string2, len);
	printf("bzero : %s\n", string1);
	print_bytes(string1, 30);
	printf("ft_bzero : %s\n", string2);
	print_bytes(string2, 30);
}

int	main(void)
{
	test(0);
	test(5);
	test(20);
	return (0);
}
*/