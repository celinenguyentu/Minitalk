/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:52:30 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/08 15:49:31 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (!dst && !src)
		return (NULL);
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		idx++;
	}
	return (dst);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

void	test(size_t len)
{
	char	string1[20] = "Hello world !";
	char	string2[20] = "Hello world !";
	char	string3[20] = "friend";
	char	string4[20] = "Hello world !";
	char	string5[20] = "Hello world !";
	void	*nullptr = NULL;

	printf("Destination string : \"%s\"\n", string1);
	printf("Copying \"%s\" to 6th char (n = %ld)\n", string3, len);
	memcpy(string1 + 6, string3, len);
	ft_memcpy(string2 + 6, string3, len);
	printf("memcpy : %s\n", string1);
	printf("ft_memcpy : %s\n", string2);
	printf("Copying \"%s\" to 6th char (n = %ld)\n", string4, len);
	memcpy(string4 + 6, string4, len);
	ft_memcpy(string5 + 6, string5, len);
	printf("memcpy : %s\n", string4);
	printf("ft_memcpy : %s\n", string5);
	if (len > 6)
		printf("Memory areas overlap ! Use memmove instead.\n");
	//printf("Destination string is NULL\n"); // CRASH
	//memmove(nullptr, string3, len);
	//ft_memmove(nullptr, string3, len);
	//printf("Source string is NULL\n"); // CRASH
	//memmove(string3, nullptr, len);
	//ft_memmove(string3, nullptr, len);
	printf("Destination and source strings are both NULL\n"); // NO CRASH
	memmove(nullptr, nullptr, len);
	ft_memmove(nullptr, nullptr, len);
	printf("memmove : %p\n", nullptr);
	printf("ft_memmove : %p\n", nullptr);
}

int	main(void)
{
	test(0);
	printf("\n");
	test(3);
	printf("\n");
	test(6);
	printf("\n");
	test(10);
	return (0);
}
*/