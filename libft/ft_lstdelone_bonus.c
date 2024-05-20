/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:20:03 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/05 23:03:08 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*	//TEST CASES
#include <stdio.h>

void	ft_del_content(void *content)
{
	printf("deleting \"%s\"\n", (char *)content);
}

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Hello");
	if (!node)
		printf("Memory allocation failed.\n");
	else
	{
		ft_lstdelone(node, &ft_del_content);
	}
	return (0);
}
*/