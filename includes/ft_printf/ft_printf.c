/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:36:02 by cxu               #+#    #+#             */
/*   Updated: 2023/05/23 17:12:46 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_check_formats(string[i], args, &length);
			i++;
		}
		else
		{
			ft_putcharacter_length(string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
