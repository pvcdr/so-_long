/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:44:26 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 15:51:23 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_split_map(t_map *map, char *map_line)
{
	map->map_tab = ft_split(map_line, '/');
	if (!map->map_tab)
		ft_free_char (map_line);
	map->map_cpy = ft_split(map_line, '/');
	if (!map->map_cpy)
	{
		ft_free_map(map->map_tab);
		ft_free_char (map_line);
	}
	map->map_cpy_2 = ft_split(map_line, '/');
	if (!map->map_cpy_2)
	{
		ft_free_map(map->map_tab);
		ft_free_map(map->map_cpy);
		ft_free_char (map_line);
	}
	free(map_line);
}
