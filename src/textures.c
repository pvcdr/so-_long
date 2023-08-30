/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:45:58 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 13:45:20 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	set_char(int keycode, t_map *map)
{
	if (keycode != 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->player, map->p_x * 30, map->p_y * 31);
}

void	set_ground(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->ground, x * 30, y * 31);
	map->map_tab[map->p_y][map->p_x] = '0';
}

void	check_item(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'C')
		map->get_c++;
}

int	check_exit(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'E')
	{
		if (map->nb_c == map->get_c)
		{
			ft_printf("\nYou won !\n\n");
			close_game(map);
		}
		else
			return (1);
	}
	return (0);
}
