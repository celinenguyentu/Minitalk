/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:23:11 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 20:43:03 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	idx;

	idx = 0;
	while (s && f && s[idx])
	{
		f(idx, &s[idx]);
		idx++;
	}
}

/*	//TEST CASES
#include <stdio.h>

void	roller_coaster(unsigned int i, char *c)
{
	if (i % 2)
		*c = ft_tolower(*c);
	else
		*c = ft_toupper(*c);
}

int	main(void)
{
	char	str[] = "Hello les cocos !";

	printf("Before ft_striteri : %s\n", str);
	ft_striteri(str, &roller_coaster);
	printf("After ft_striteri : %s\n", str);
	return (0);
}
*/