/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:54:31 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/08 18:07:06 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;
	size_t	size;

	idx = 0;
	size = 0;
	while (s[idx] && idx < start)
		idx++;
	while (s[idx + size] && size < len)
		size++;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	while (size > 0)
	{
		substr[size - 1] = s[idx + size - 1];
		size--;
	}
	return (substr);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	string[] = "Hello les cocos !";
	char	*sub1 = ft_substr(string, 0, 5);
	char	*sub2 = ft_substr(string, 6, 30);

	printf("Source : %s\n", string);
	if (!sub1)
		printf("Memory allocation failed.\n");
	else
		printf("Substring from idx = %d of length len = %d\n%s\n", 0, 5, sub1);
	if (!sub2)
		printf("Memory allocation failed.\n");
	else
		printf("Substring from idx = %d of length len = %d\n%s\n", 6, 30, sub2);
	free(sub1);
	free(sub2);
}
*/