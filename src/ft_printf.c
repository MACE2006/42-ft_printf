/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:39:55 by cvorley           #+#    #+#             */
/*   Updated: 2025/11/10 13:39:56 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		count;
	char	*start;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			start = (char *)str;
			if (*(++str))
				count += pft_parse((char *)str, ap);
			while (*str && !ft_strchr(SPECIFY, *str))
				str++;
			if (!(*str))
				str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		if (*str)
			str++;
	}
	va_end(ap);
	return (count);
}

int	pft_print_form(t_format f, va_list ap)
{
	int	n;

	n = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		n = pft_print_c(f, ap);
	if (f.specifier == 's')
		n = pft_print_s(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		n = pft_print_diu(f, ap);
	if (f.specifier == 'X' || f.specifier == 'x')
		n = pft_print_x(f, ap);
	if (f.specifier == 'p')
		n = pft_print_p(f, ap);
	return (n);
}

t_format	pft_new_format(void)
{
	t_format	new_form;

	new_form.minus = 0;
	new_form.plus = 0;
	new_form.width = 0;
	new_form.prec = 0;
	new_form.neg_prec = 0;
	new_form.zero = 0;
	new_form.dot = 0;
	new_form.space = 0;
	new_form.sharp = 0;
	new_form.specifier = 0;
	return (new_form);
}

int	main()
{
	ft_printf("%s\n", "idk some bs");
}