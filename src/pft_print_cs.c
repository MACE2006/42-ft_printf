/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_print_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <cvorley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:44:22 by cvorley           #+#    #+#             */
/*   Updated: 2025/11/17 10:44:01 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdlib.h>

int	pft_print_s(t_format f, va_list ap)
{
	char	*str;
	int		count;
	int		has_malloc;

	count = 0;
	has_malloc = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		str = malloc(sizeof(char) * 7);
		has_malloc = 1;
		ft_strlcpy(str, "(null)", 7);
	}
	if (!f.dot || f.prec > (int)ft_strlen(str) || f.prec < 0)
		f.prec = ft_strlen(str);
	if (! f.minus && f.width > f.prec && f.zero && (!f.dot || f.neg_prec))
		count += pft_putnchar_fd('0', 1, f.width - f.prec);
	else if (!f.minus && f.width - f.prec > 0)
		count += pft_putnchar_fd(' ', 1, f.width - f.prec);
	count += pft_putstrn_fd(str, 1, f.prec);
	if (f.minus && f.width - f.prec > 0)
		count += pft_putnchar_fd(' ', 1, f.width - f.prec);
	if (has_malloc)
		free (str);
	return (count);
}

int	pft_print_c(t_format f, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
	 	c = '%';
	f.prec = 1;
	if (!f.minus && f.zero)
		count += pft_putnchar_fd('0', 1, f.width - f.prec);
	else if (!f.minus && f.width > f.prec)
		count += pft_putnchar_fd(' ', 1, f.width - f.prec);
	ft_putchar_fd(c, 1);
	count++;
	if (f.minus && f.width - f.prec > 0)
		count += pft_putnchar_fd(' ', 1, f.width - f.prec);
	return (count);
}
