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
#include <unistd.h>

int	pft_putnchar_fd(char c, int fd, int n)
{
	int	i;

	i = 0;
	while (n-- > 0)
		i += (int)write(fd, &c, 1);
	return (i);
}

int	pft_putstrn_fd(char *s, int fd, int n)
{
	if (s != NULL)
		return ((int)write(fd, s, n));
	return (0);
}

static char *pft_allo(char *str, int len, unsigned int n, unsigned int n_b)
{
	if (n_b == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	pft_nbrlen(unsigned long nbr, unsigned long base)
{
	unsigned long	len;

	len = 0;
	if (!base)
		base = 10;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

char	*pft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	n_b;

	n_b = n;
	len = pft_nbrlen(n , 10);
	str = NULL;
	str = pft_allo(str, len, n, n_b);
	if (!str)
		return (NULL);
	return (str);
}
