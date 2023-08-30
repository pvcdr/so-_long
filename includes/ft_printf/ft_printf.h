/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:36:53 by cxu               #+#    #+#             */
/*   Updated: 2023/05/19 11:33:40 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_check_formats(char s, va_list args, int *len);
void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *str, int *length);
void	ft_putnbr(int n, int *length);
void	ft_pointer(unsigned long long pointer, int *length);
void	ft_hexadecimal(unsigned int s, int *length, char x);
void	ft_unsigned_int(unsigned int u, int *length);

#endif