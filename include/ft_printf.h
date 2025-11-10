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

typedef struct s_format
{
	int	smt;
}	t_format;

int	ft_printf(const char *str, ...);

#endif
