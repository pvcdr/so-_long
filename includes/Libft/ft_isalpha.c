/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:33:50 by cxu               #+#    #+#             */
/*   Updated: 2023/05/08 11:15:29 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isalpha(int i)
{
	if (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z'))
		return (1);
	return (0);
}