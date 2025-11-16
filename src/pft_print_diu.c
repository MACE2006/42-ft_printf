/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:44:22 by cvorley           #+#    #+#             */
/*   Updated: 2025/11/11 11:44:23 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	plus(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.width -= (f.space && !neg && !f.plus && f.width);
	if (neg || f.plus)
		c += pft_putnchar_fd(plus(f), 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += pft_putnchar_fd(' ', 1, f.zero && !f.dot);
	if (!f.minus && f.width > f.prec && (!f.dot || f.neg_prec) && f.zero)
		c += pft_putnchar_fd('0', 1, f.width - f.prec - neg - f.plus);
	else if (!f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, f.width - f.prec - neg - f.plus);
	if ((neg || f.plus) && ft_strncmp(nbr, "-2147483648", 12))
		c += pft_putnchar_fd(plus(f), 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space && ft_strncmp(nbr, "-2147483648", 12))
		c += pft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += pft_putnchar_fd('0', 1, f.prec - len);
	c += write(1, nbr, len);
	if (f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, f.width - f.prec - neg - f.plus);
	return (c);
}

int	pft_prit_diu(t_format f, va_list ap)
{
	char	*nbr;
	int		len;
	int		neg;
	int		c;
	int		n;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = pft_uitoa((unsigned)n);
	else
	 	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.prec && f.dot)
		len = 0;
	if (f.prec < len || !f.dot)
		f.prec = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free (nbr);
	return (c);
}