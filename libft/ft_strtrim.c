/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:41:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	size;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, s1[size - 1]))
		size--;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	return (result);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	string[] = " abc\nHello\t42! \tbbc \n";
	char	set[] = " abc\n\t";

	char	*trimmed = ft_strtrim(string, set);
	if (!trimmed)
		printf("Memory allocation failed.\n");
	else
		printf("Trimmed string : %s\n", trimmed);
	free(trimmed);
	return (0);
}
*/