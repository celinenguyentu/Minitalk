/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:26:22 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/20 19:03:24 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*	//TEST CASES
#include <stdio.h>

int	main(void)
{
	int		data1 = 42;
	char	*data2 = "Hello";
	t_list	*elem1 = ft_lstnew(&data1);
	t_list	*elem2 = ft_lstnew(data2);

	if (!elem1)
		printf("Memory allocation failed.\n");
	else
	{
		printf("First node content : %d\n", *(int *)elem1->content);
		if (elem1->next)
			printf("Member next is not NULL.\n");
	}
	if (!elem2)
		printf("Memory allocation failed.\n");
	else
	{
		printf("Second node content : %s\n", (char *)elem2->content);
		if (elem2->next)
			printf("Member next is not NULL.\n");
	}
	free(elem1);
	free(elem2);
	return (0);
}
*/