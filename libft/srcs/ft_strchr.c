/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:38:34 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 18:08:08 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	string[] = "Hello world !";
	int			chr[5] = {'o', 'c', '\0', '\x7f', 'H' + 256};

	printf("Source : %s\n\n", string);
	for (int i = 0; i < 5; i++)
	{
		printf("Looking for '%c'\n", chr[i]);
		printf("strchr : %p\n", strchr(string, chr[i]));
		printf("ft_strchr : %p\n\n", ft_strchr(string, chr[i]));
	}
	return (0);
}
*/