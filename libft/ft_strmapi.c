/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:32:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/06 17:31:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

/*	//TEST CASES
#include <stdio.h>

char	ft_roller_coaster(unsigned int i, char c)
{
	if (i % 2)
		return (ft_tolower(c));
	else
		return (ft_toupper(c));
}

int	main(void)
{
	char	str[] = "Hello les cocos !";
	char	*cpy;

	printf("Source : %s\n", str);
	cpy = ft_strmapi(str, &ft_roller_coaster);
	if (!cpy)
		printf("Memory allocation failed.\n");
	else
		printf("Modified copy : %s\n", cpy);
	free(cpy);
	return (0);
}
*/