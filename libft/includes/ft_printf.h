/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/18 22:12:25 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <limits.h>
# include "libft.h"

# define SPECIFIERS "cspdiuxX%o"
# define FLAGS "-0# +"
# define SYMBOLS "-0# +*."
# define LOWHEXADECIMAL "0123456789abcdef"
# define UPHEXADECIMAL "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define OCTAL "01234567"

typedef struct s_specs
{
	int		dash;
	int		zero;
	int		hash;
	int		blank;
	int		plus;
	int		star_width;
	long	width;
	int		star_precis;
	long	precis;
	char	specif;
	int		n_chars;
	int		n_unknowns;
}	t_specs;

// ft_printf helpers
int		print_arg(t_specs specs, va_list *args, int n_chars);
ssize_t	print_char(t_specs specs, va_list *args);
ssize_t	print_str(t_specs specs, va_list *args);
ssize_t	print_ptr(t_specs specs, va_list *args);
ssize_t	print_int(t_specs specs, va_list *args);
ssize_t	print_uint(t_specs specs, va_list *args, int baselen);
ssize_t	print_percent(t_specs specs);
ssize_t	print_unknown(t_specs specs);
ssize_t	print_intprefix(t_specs specs, int uarg_len, int sign);
void	precision_overflow_handler(t_specs *specs, int arg_len);
int		check(ssize_t *n_chars, ssize_t bytes_written);

// formatspec
void	init_formatspecs(t_specs *specs);
void	reset_formatspecs(t_specs *specs);
void	update_formatspecs(t_specs *specs, const char **format, va_list *args);
void	clean_formatspecs(t_specs *specs);

// Utility functions
ssize_t	ft_putchar(unsigned char c);
ssize_t	ft_putnchar(unsigned char c, ssize_t n);
ssize_t	ft_putnstr(const char *str, size_t n);
long	ft_atoi_digits(const char *str);
int		ft_strdlen(const char *str);
ssize_t	ft_putuint(unsigned long int n, int base);
size_t	ft_uintlen(unsigned long int n, int base);

#endif