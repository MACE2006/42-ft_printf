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

static int	pft_hex(t_format f, size_t n, size_t i)
{
	int		c;
	int		r;
	char	ch;

	c = 0;
	if (n > 0 || (!i && (f.specifier != 'p' || !f.dot)))
	{
		r = n % 16;
		if (f.specifier != 'X')
			ch = HEXLOW[r];
		else
			ch = HEXUP[r];
		n /= 16;
		i = 1;
		c += pft_hex(f, n, i);
		ft_putchar_fd(ch, 1);
		c++;
	}
	return (c);
}

static char	*pft_sh(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

int	pft_print_p(t_format f, va_list ap)
{
	int		c;
	int		len;
	size_t	n;

	c = 0;
	n = va_arg(ap, size_t);
	if (!n && !f.dot)
		return (write(1, "(nil)", 5));
	len = pft_nbrlen(n, 16) * !(!n && !f.prec && f.dot);
	if (f.prec < len || !f.dot)
		f.prec = len;
	c += write(1, "0x", 2 * f.zero);
	f.width -= 2;
	if (!f.minus && f.width > f.prec && !f.dot && f.zero)
		c += pft_putnchar_fd('0', 1, (f.width - f.prec));
	else if (!f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, (f.width - f.prec));
	c += write(1, "0x", 2 * !f.zero);
	c += pft_putnchar_fd('0', 1, (f.prec - len) * (n != 0));
	c += pft_putnchar_fd('0', 1, f.prec * (f.dot && !n));
	if (len)
		c += pft_hex(f, n, n);
	if (f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, f.width - f.prec);
	return (c);
}

int	pft_print_x(t_format f, va_list ap)
{
	int				c;
	int				len;
	unsigned int	n;

	c = 0;
	n = va_arg(ap, unsigned int);
	len = pft_nbrlen(n, 16);
	if (!n && !f.prec && f.dot)
		len = 0;
	if (f.prec < 0 || f.prec < len || !f.dot)
		f.prec = len;
	if (f.sharp && n)
		f.width -= 2;
	c += pft_putstrn_fd(pft_sh(f), 1, 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.width > f.prec && (!f.dot || f.neg_prec) && f.zero)
		c += pft_putnchar_fd('0', 1, (f.width - f.prec));
	else if (!f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, (f.width - f.prec));
	c += pft_putstrn_fd(pft_sh(f), 1, 2 * (f.sharp && !f.zero && n));
	c += pft_putnchar_fd('0', 1, (f.prec - len));
	if (len)
		c += pft_hex(f, n, n);
	if (f.minus && f.width > f.prec)
		c += pft_putnchar_fd(' ', 1, f.width - f.prec);
	return (c);
}
