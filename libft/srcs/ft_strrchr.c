/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:41:47 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 18:25:51 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		last = (char *)s;
	return (last);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	string[] = "Hello world !";
	int			chr[4] = {'o', 'c', '\0', '\x7f'};

	printf("Source : %s\n\n", string);
	for (int i = 0; i < 4; i++)
	{
		printf("Looking for '%c'\n", chr[i]);
		printf("strrchr : %p\n", strrchr(string, chr[i]));
		printf("ft_strrchr : %p\n\n", ft_strrchr(string, chr[i]));
	}
	return (0);
}
*/