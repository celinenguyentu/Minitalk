/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:54:31 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/22 15:28:29 by cnguyen-         ###   ########.fr       */
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
	if (!s)
		return (NULL);
	while (idx < start && s[idx])
		idx++;
	while (size < len && s[idx + size])
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
	char	*sub3 = ft_substr(NULL, 5, 5);

	printf("Source : %s\n", string);
	if (!sub1)
		printf("An error occured.\n");
	else
		printf("Substring from idx = %d of length len = %d\n%s\n", 0, 5, sub1);
	if (!sub2)
		printf("An error occured.\n");
	else
		printf("Substring from idx = %d of length len = %d\n%s\n", 6, 30, sub2);
	if (!sub3)
		printf("An error occured.\n");
	else
		printf("Substring from idx = %d of length len = %d\n%s\n", 5, 5, sub3);
	free(sub1);
	free(sub2);
}
*/