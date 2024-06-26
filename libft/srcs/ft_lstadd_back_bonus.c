/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:29:06 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/26 02:37:36 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	current = *lst;
	while (current && current->next)
		current = current->next;
	if (!current)
		*lst = new;
	else
		current->next = new;
}

/*	//RECURSIVE VERSION
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(&(*lst)->next, new);
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
		ft_print_list(lst);
	}
	ft_lstclear(&lst, &ft_del_content);
	return (0);
}
*/