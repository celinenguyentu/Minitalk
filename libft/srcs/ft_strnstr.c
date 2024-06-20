/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 04:08:54 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 18:45:41 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*	//TEST CASES
#include <string.h>
#include <stdio.h>
#include <bsd/string.h> // on Linux compile with flag -lbsd

int	main(void)
{
	char	haystack[] = "Hello les frères, hello les soeurs";
	char	*needles[] = {"", "Hell", "Help", "les", NULL};
	size_t	n_idx = 0;
	size_t	len;
	char	*result;

	while (needles[n_idx])
	{
		len = 0;
		printf("\"%s\" needle \"%s\"\n", haystack, needles[n_idx]);
		while (len <= 10)
		{
			result = strnstr(haystack, needles[n_idx], len);
			printf("strnstr\t\t%ld\t%s\n", len, result);
			result = ft_strnstr(haystack, needles[n_idx], len);
			printf("ft_strnstr\t%ld\t%s\n", len, result);
			len++;
		}
		printf("\n");
		n_idx++;
	}
	return (0);
}
*/