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



int	pft_parse(char *str, va_list ap)
{
	t_format	nw_frt;

	nw_frt = pft_parse_width(str, ap, pft_new_format());
	nw_frt = sm other bs;
	while (!ft_strchr(SPECIFY, *str) && *str != '.')
		str++;
	if (*str == '.' && !nw_frt.specifier)
}
