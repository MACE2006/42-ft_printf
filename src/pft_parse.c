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

static t_format	pft_parse_width(char *str, va_list ap, t_format f)
{
	int	smt;
	
	smt = 0;
	while (*str != '.' && !ft_strchr(SPECIFY, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == 0 && !ft_isdigit(*(str - 1)))
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

static t_format	ft_parse_bullshiti()

int	pft_parse(char *str, va_list ap)
{
	t_format	nw_frt;

	nw_frt = pft_parse_width(str, ap, pft_new_format());
	nw_frt = sm other bs;
	while (!ft_strchr(SPECIFY, *str) && *str != '.')
		str++;
	if (*str == '.' && !nw_frt.specifier)
}
