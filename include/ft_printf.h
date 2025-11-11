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
# include <stdarg.h>

# define SPECIFY "csdiupxX%"

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

int	ft_printf(const char *str, ...);
int	pft_parse(char *str, va_list ap);

#endif
