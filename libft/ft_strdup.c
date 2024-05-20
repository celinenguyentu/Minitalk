/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:36:55 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/06 17:30:32 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*src = "Hello 42 !";
	char	*cpy1;
	char	*cpy2;

	cpy1 = strdup(src);
	cpy2 = ft_strdup(src);
	printf("Source : %s\n", src);
	if (!cpy1)
		printf("Memory allocation failed.\n");
	else
		printf("strdup : %s\n", cpy1);
	if (!cpy2)
		printf("Memory allocation failed.\n");
	else
		printf("ft_strdup : %s\n", cpy2);
	free(cpy1);
	free(cpy2);
	return (0);
}
*/