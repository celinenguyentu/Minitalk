/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:05:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 20:39:11 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strslen(char const *str, char strend)
{
	size_t	idx;

	idx = 0;
	while (str[idx] && str[idx] != strend)
		idx++;
	return (idx);
}

static size_t	ft_count_strings(char const *str, char sep)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != sep)
		{
			str += ft_strslen(str, sep);
			count++;
		}
		else
			str++;
	}
	return (count);
}

static void	*ft_clean(char **strs, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
		free(strs[idx++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	idx;

	if (!s)
		return (NULL);
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
	char	**strs = ft_split(string, 'o');

	if (!strs)
		printf("An error occured.\n");
	else
	{
		int	idx = 0;
		while (strs[idx])
		{
			printf("%s\n", strs[idx]);
			idx++;
		}
		ft_clean(strs, idx);
	}
	return (0);
}
*/