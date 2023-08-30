/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:45:49 by cxu               #+#    #+#             */
/*   Updated: 2023/08/24 16:00:10 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_map *map)
{
	int		img_width;
	int		img_height;

	map->player = mlx_xpm_file_to_image
		(map->mlx, "xpm/player.xpm", &img_width, &img_height);
	if (!map->player)
		close_game(map);
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "xpm/wall.xpm", &img_width, &img_height);
	if (!map->wall)
		close_game(map);
	map->ground = mlx_xpm_file_to_image
		(map->mlx, "xpm/ground.xpm", &img_width, &img_height);
	if (!map->ground)
		close_game(map);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "xpm/exit.xpm", &img_width, &img_height);
	if (!map->exit)
		close_game(map);
	map->chest = mlx_xpm_file_to_image
		(map->mlx, "xpm/chest.xpm", &img_width, &img_height);
	if (!map->chest)
		close_game(map);
}

void	ft_set_item(t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->chest, pos.x * 30, pos.y * 31);
	}
	else if (map->map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->exit, pos.x * 30, pos.y * 31);
	else if (map->map_tab[pos.y][pos.x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->player, pos.x * 30, pos.y * 31);
		map->p_x = pos.x;
		map->p_y = pos.y;
	}
}

void	ft_set_img(t_map *map)
{
	t_pos	pos;

	pos.y = 0;
	while (map->map_tab[pos.y])
	{
		pos.x = 0;
		while (map->map_tab[pos.y][pos.x])
		{
			if (map->map_tab[pos.y][pos.x] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->wall, pos.x * 30, pos.y * 31);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->ground, pos.x * 30, pos.y * 31);
				ft_set_item(map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(t_map *map)
{
	map->player = 0;
	map->chest = 0;
	map->wall = 0;
	map->ground = 0;
	map->exit = 0;
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free(map->mlx);
		return ;
	}
	map->mlx_win = mlx_new_window(map->mlx, (map->width * 30),
			(map->height * 31), "so_long");
	ft_init_img(map);
	ft_set_img(map);
	ft_game(map);
	mlx_loop(map->mlx);
}
