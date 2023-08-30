/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:49:03 by cxu               #+#    #+#             */
/*   Updated: 2023/05/19 11:32:36 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_formats(char s, va_list args, int *len)
{
	if (s == 's')
		ft_string(va_arg(args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(args, unsigned long long), len);
	else if (s == 'c')
		ft_putcharacter_length(va_arg(args, int), len);
	else if (s == '%')
		ft_putcharacter_length('%', len);
}
