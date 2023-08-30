/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:47:09 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 14:42:13 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_char(char *str)
{
	free(str);
	exit (1);
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][++x])
		{
			if (map->map_tab[y][x] == 'P')
			{
				map->start_y = y;
				map->start_x = x;
				return ;
			}
		}
		y++;
	}
}

int	ft_exit_error(char **cpy, int y, int x)
{
	if (cpy[y][x] == '1' || cpy[y][x] == 'V')
		return (0);
	if (cpy[y][x] == 'E')
		return (1);
	cpy[y][x] = 'V';
	if (ft_exit_error(cpy, y, x + 1) || ft_exit_error(cpy, y, x - 1)
		|| ft_exit_error(cpy, y + 1, x)
		|| ft_exit_error(cpy, y - 1, x))
		return (1);
	return (0);
}

void	ft_coins_error(t_map *map, char **cpy, int y, int x)
{
	if (cpy[y][x] == '1' || cpy[y][x] == 'V'
	|| cpy[y][x] == 'E' || cpy[y][x] == 'c')
		return ;
	if (cpy[y][x] == 'C')
	{
		cpy[y][x] = 'c';
		map->count_c++;
	}
	if (cpy [y][x] != 'c')
		cpy[y][x] = 'V';
	ft_coins_error(map, cpy, y, x + 1);
	ft_coins_error(map, cpy, y, x - 1);
	ft_coins_error(map, cpy, y + 1, x);
	ft_coins_error(map, cpy, y - 1, x);
}

int	ft_error2(t_map *map)
{
	map->count_c = 0;
	find_player(map);
	if (!ft_exit_error(map->map_cpy, map->start_y, map->start_x))
	{
		ft_printf("%d, %d", map->start_y, map->start_x);
		ft_printf("Error\nMap invalid exit\n");
		return (0);
	}
	ft_coins_error(map, map->map_cpy_2, map->start_y, map->start_x);
	if (map->count_c != map->nb_c)
	{
		ft_printf("Error\nMap invalid coin\n");
		return (0);
	}
	return (1);
}
