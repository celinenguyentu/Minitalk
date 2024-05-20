/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:16:17 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/05 23:16:27 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}

/*	//ITERATIVE VERSION
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;
	
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
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
	ft_lstclear(&lst, &ft_del_content);
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
	ft_print_list(lst);
	return (0);
}
*/