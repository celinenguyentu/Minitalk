/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:10:55 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 19:01:55 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_idx;
	size_t	src_idx;

	dst_idx = 0;
	src_idx = 0;
	if (dst || dstsize != 0)
	{
		while (dst[dst_idx] && dst_idx < dstsize)
			dst_idx++;
		if (dst_idx < dstsize)
		{
			while (src[src_idx] && dst_idx + src_idx < dstsize - 1)
			{
				dst[dst_idx + src_idx] = src[src_idx];
				src_idx++;
			}
			dst[dst_idx + src_idx] = '\0';
		}
	}
	while (src[src_idx])
		src_idx++;
	return (dst_idx + src_idx);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>
#include <bsd/string.h> // on Linux, compile with flag -lbsd

void	test(const char *src, unsigned int dsize)
{
	char	dest_og[100] = "Hello ";
	char	dest_mine[100] = "Hello ";
	int		n_og;
	int		n_mine;

	printf("Source : '%s'\n", src);
	printf("dsize = %d\n", dsize);
	n_og = strlcat(dest_og, src, dsize);
	printf("strlcat : '%s', returned length %d\n", dest_og, n_og);
	n_mine = ft_strlcat(dest_mine, src, dsize);
	printf("ft_strlcat : '%s', returned length %d\n\n", dest_mine, n_mine);
}

int	main(void)
{
	test("", 10);
	test("World of 42!", 0);
	test("World of 42!", 4);
	test("World of 42!", 6);
	test("World of 42!", 10);
	test("World of 42!", 20);
	return (0);
}
*/