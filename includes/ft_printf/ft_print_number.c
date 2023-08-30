/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:07:55 by cxu               #+#    #+#             */
/*   Updated: 2023/05/22 09:50:48 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *length)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putcharacter_length('-', length);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, length);
		ft_putcharacter_length(nb % 10 + '0', length);
	}
	if (nb <= 9)
	{
		ft_putcharacter_length(nb % 10 + '0', length);
	}
}

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}

void	ft_pointer(unsigned long long pointer, int *length)
{
	char	string[20];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_length(string[i], length);
	}
}

void	ft_hexadecimal(unsigned int s, int *length, char x)
{
	char	*base_character;

	if (x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	if (s == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	if (s >= 16)
		ft_hexadecimal(s / 16, length, x);
	ft_putcharacter_length(base_character [s % 16], length);
}
