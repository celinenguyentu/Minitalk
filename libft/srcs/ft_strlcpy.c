/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:04:46 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 18:55:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize != 0)
	{
		while (src[idx] && idx < dstsize - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	while (src[idx])
		idx++;
	return (idx);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>
#include <bsd/string.h> // on Linux compile with flag -lbsd

void	test(const char *src, unsigned int size)
{
	char			dest_og[20];
	char			dest_mine[20];
	int				n_og;
	unsigned int	n_mine;

	n_og = strlcpy(dest_og, src, size);
	n_mine = ft_strlcpy(dest_mine, src, size);
	printf("Source : '%s'\n", src);
	printf("Copying %d characters\n", size);
	printf("strlcpy : '%s', return length %d\n", dest_og, n_og);
	printf("ft_strlcpy : '%s', return length %d\n\n", dest_mine, n_mine);
}

int	main(void)
{
	test("", 20);
	test("Hello world !", 20);
	test("Hello world !", 14);
	test("Hello world !", 10);
	test("Hello world !", 1);
	test("Hello world !", 0);
	return (0);
}
*/