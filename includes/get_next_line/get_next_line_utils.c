/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:44:03 by cxu               #+#    #+#             */
/*   Updated: 2023/08/24 12:56:48 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2));
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
		tab[i++] = *s2++;
	tab[size] = '\0';
	free(s1);
	return (tab);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int				i;
	unsigned char	search;

	search = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != search)
		i++;
	if (s[i] == search)
		return ((char *)s + i);
	else
		return (NULL);
}
