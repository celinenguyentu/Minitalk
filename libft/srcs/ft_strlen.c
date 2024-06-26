/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:33:47 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 19:49:43 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*	//TEST CASES
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "Hello 42!";
	char	*str2 = "";

	printf("Input: \"%s\"\n", str1);
	printf("strlen: %zu\n", strlen(str1));
	printf("ft_strlen: %zu\n\n", ft_strlen(str1));
	printf("Input: \"%s\"\n", str2);
	printf("strlen: %zu\n", strlen(str2));
	printf("ft_strlen: %zu\n", ft_strlen(str2));
	return (0);
}
*/