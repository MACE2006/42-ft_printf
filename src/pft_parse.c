/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <cvorley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:44:22 by cvorley           #+#    #+#             */
/*   Updated: 2025/11/18 11:39:37 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_format	pft_parse_width(char *str, va_list ap, t_format f)
{
	int	smt;

	smt = 0;
	while (*str != '.' && !ft_strchr(SPECIFY, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !smt)
		{
			if (*str == '*')
				f.width = va_arg(ap, int);
			else
				f.width = ft_atoi(str);
			smt = 1;
		}
		str++;
	}
	return (f);
}

static t_format	pft_pars_precision(char *str, va_list ap, t_format f)
{
	int	i;

	i = 0;
	while (!ft_strchr(SPECIFY, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !i)
		{
			if (*str == '*')
				f.prec = va_arg(ap, int);
			else
				f.prec = ft_atoi(str);
			i = 1;
		}
		str++;
	}
	return (f);
}

static t_format	pft_parse_pss(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECIFY, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

int	pft_parse(char *str, va_list ap)
{
	t_format	nw_frt;

	nw_frt = pft_parse_width(str, ap, pft_new_format());
	nw_frt = pft_parse_pss(str, nw_frt);
	while (!ft_strchr(SPECIFY, *str) && *str != '.')
		str++;
	if (*str == '.' && !nw_frt.specifier)
	{
		nw_frt.dot = 1;
		nw_frt = pft_pars_precision(str++, ap, nw_frt);
		while (!ft_strchr(SPECIFY, *str))
			str++;
	}
	if (nw_frt.width < 0)
	{
		nw_frt.minus = 1;
		nw_frt.width *= -1;
	}
	nw_frt.specifier = *str;
	nw_frt.neg_prec = nw_frt.prec < 0;
	return (pft_print_form(nw_frt, ap));
}
