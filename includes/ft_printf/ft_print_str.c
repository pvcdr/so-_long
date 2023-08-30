/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:08:34 by cxu               #+#    #+#             */
/*   Updated: 2023/05/24 16:58:24 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void	ft_string(char *str, int *length)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		(*length)++;
	}
}
