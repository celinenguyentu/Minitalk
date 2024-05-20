/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:30:00 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/09 17:39:04 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
	ft_putchar_fd('\n', fd);
}

/*	//TEST CASES
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*test_cases[] = {"Hello 42!", "Coucou 42!", "Hola 42!"};
	int		fd = open("ft_putendl_fd_test", O_CREAT | O_RDWR, 0777);

	printf("Standard input :\n");
	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		ft_putendl_fd(test_cases[i], STDIN_FILENO);
	printf("Standard output :\n");
	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		ft_putendl_fd(test_cases[i], STDOUT_FILENO);
	printf("Standard error :\n");
	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		ft_putendl_fd(test_cases[i], STDERR_FILENO);
	if (fd != -1)
	{
		printf("New file : check file ft_putendl_fd_test\n");
		for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
			ft_putendl_fd(test_cases[i], fd);
		close(fd);
	}
	return (0);
}
*/