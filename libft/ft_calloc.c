/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:57:59 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/08 12:34:48 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = count * size;
	if (total_size && total_size / count != size)
		return (NULL);
	result = (void *)malloc(total_size);
	if (!result)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}

/*	//TEST CASES
#include <stdio.h>
#include <limits.h>

void	test(size_t count, size_t size)
{
	void		*og;
	void		*mine;

	og = calloc(count, size);
	mine = ft_calloc(count, size);
	printf("Inputs : count = %ld, size = %ld\n", count, size);
	if (!og)
		printf("calloc : NULL\n");
	else
	{
		printf("calloc : %p\n", og);
		free(og);
	}
	if (!mine)
		printf("ft_calloc : NULL\n");
	else
	{
		printf("ft_calloc : %p\n", mine);
		free(mine);
	}
}

int	main(void)
{
	test(2, 2);
	test(SIZE_MAX, SIZE_MAX);
	test(INT_MAX, INT_MAX);
	test(INT_MIN, INT_MIN);
	test(0, 0);
	test(0, 5);
	test(5, 0);
	test(-5, -5);
	test(0, -5);
	test(-5, 0);
	test(3, -5);
	test(-5, 3);
	return (0);
}
*/