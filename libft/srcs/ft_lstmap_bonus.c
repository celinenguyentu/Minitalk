/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:05:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 03:14:54 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*elem;
	void	*content;

	result = NULL;
	while (lst && f && del)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, elem);
		lst = lst->next;
	}
	return (result);
}

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

void	*ft_same(void *content)
{
	return (content);
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
	t_list	*lst_cap = ft_lstmap(lst, &ft_same, &ft_del_content);
	ft_print_list(lst_cap);
	ft_lstclear(&lst, &ft_del_content);
	ft_lstclear(&lst_cap, &ft_del_content);
	ft_print_list(lst);
	ft_print_list(lst_cap);
	return (0);
}
*/