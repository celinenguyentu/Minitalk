/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:15:02 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/06 17:27:12 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	idx;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (*s1)
		str[idx++] = *s1++;
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	return (str);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = " ";
	char	s3[] = "42!";

	char	*joined1 = ft_strjoin(s1, s2);
	if (!joined1)
		printf("Memory allocation failed.\n");
	else
		printf("Joined string : %s\n", joined1);
	char	*joined2 = ft_strjoin(joined1, s3);
	if (!joined2)
		printf("Memory allocation failed.\n");
	else
		printf("Joined string : %s\n", joined2);
	free(joined1);
	free(joined2);
	return (0);
}
*/