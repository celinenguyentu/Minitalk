/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:32:36 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 20:41:51 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	if (!s || !f)
		return (NULL);
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

char	roller_coaster(unsigned int i, char c)
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
	cpy = ft_strmapi(str, &roller_coaster);
	if (!cpy)
		printf("An error occured.\n");
	else
		printf("Modified copy : %s\n", cpy);
	free(cpy);
	return (0);
}
*/