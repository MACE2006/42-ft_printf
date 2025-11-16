/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:40:15 by cvorley           #+#    #+#             */
/*   Updated: 2025/11/10 13:40:17 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../ft_libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

# define SPECIFY "csdiupxX%"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

typedef struct s_format
{
	int	minus;
	int	plus;
	int	width;
	int	prec;
	int	neg_prec;
	int	zero;
	int	dot;
	int	space;
	int	sharp;
	int	specifier;
}	t_format;

int			ft_printf(const char *str, ...);
int			pft_parse(char *str, va_list ap);
int			pft_print_form(t_format f, va_list ap);
int			pft_print_c(t_format f, va_list ap);
int			pft_print_s(t_format f, va_list ap);
int			pft_print_diu(t_format f, va_list ap);
int			pft_print_x(t_format f, va_list ap);
int			pft_print_p(t_format f, va_list ap);
t_format	pft_new_format(void);

//util functions
int			pft_putnchar_fd(char c, int fd, int n);
int			pft_putstrn_fd(char *s, int fd, int n);
char		*pft_uitoa(unsigned int n);
int			pft_nbrlen(unsigned long nbr, unsigned long base);

#endif
