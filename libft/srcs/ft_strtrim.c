/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:41:18 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 20:25:59 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
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
		printf("An error occured.\n");
	else
		printf("Trimmed string : %s\n", trimmed);
	free(trimmed);
	return (0);
}
*/