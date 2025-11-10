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
			
		}
		else {
			count += ft_putchar_fd(*str, 1);
		}
		if (*str)
			str++;
	}
	va_end(ap);
	return (cnt);
}
