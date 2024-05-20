/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:05:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/11 03:45:10 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strslen(char const *s, char c)
{
	size_t	idx;

	idx = 0;
	while (s[idx] && s[idx] != c)
		idx++;
	return (idx);
}

static size_t	ft_count_strings(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += ft_strslen(s, c);
			count++;
		}
		else
			s++;
	}
	return (count);
}

static void	*ft_clean(char **array, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
		free(array[idx++]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	idx;

	split = (char **)malloc((ft_count_strings(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[idx] = ft_substr(s, 0, ft_strslen(s, c));
			if (!split[idx])
				return (ft_clean(split, idx));
			s += ft_strslen(s, c);
			idx++;
		}
		else
			s++;
	}
	split[idx] = NULL;
	return (split);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	char	string[] = "Coucou les cocos";
	char	**splitted = ft_split(string, ' ');

	if (!splitted)
		printf("Memory allocation failed.\n");
	else
	{
		int	idx = 0;
		while (splitted[idx])
		{
			printf("%s\n", splitted[idx]);
			idx++;
		}
		ft_clean(splitted, idx);
	}
	return (0);
}
*/