/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:51:21 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/05 23:34:20 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		f(lst->content);
		ft_lstiter(lst->next, f);
	}
}

/*	//ITERATIVE VERSION
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
*/

/*	//TEST CASES
#include <stdio.h>

void	ft_print_content(void *content)
{
	printf("\"%s\" -> ", (char *)content);
}

void	ft_print_list(t_list *lst)
{
	printf("Printing list : ");
	ft_lstiter(lst, &ft_print_content);
	printf("NULL\n");
}

void	ft_del_content(void *content)
{
	printf("deleting \"%s\"\n", (char *)content);
}

int	main(void)
{
	t_list	*lst;
	char	*contents[] = {"Hello", "les", "cocos"};

	lst = NULL;
	ft_print_list(lst);
	for (size_t i = 0; i < sizeof(contents) / sizeof(contents[0]); i++)
	{
		t_list	*node = ft_lstnew(contents[i]);
		if (!node)
			printf("Memory allocation failed.\n");
		else
			ft_lstadd_back(&lst, node);
	}
	ft_print_list(lst);
	ft_lstclear(&lst, &ft_del_content);
	return (0);
}
*/