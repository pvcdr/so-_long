/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:43:34 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 14:06:58 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_tab(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_tab[i])
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
	i = 0;
	while (map->map_cpy[i])
	{
		free(map->map_cpy[i]);
		i++;
	}
	free(map->map_cpy);
	i = 0;
	while (map->map_cpy_2[i])
	{
		free(map->map_cpy_2[i]);
		i++;
	}
	free(map->map_cpy_2);
}

void	destroy_image(t_map *map)
{
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	if (map->chest)
		mlx_destroy_image(map->mlx, map->chest);
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
	if (map->ground)
		mlx_destroy_image(map->mlx, map->ground);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
}

int	close_game(t_map *map)
{
	free_map_tab(map);
	destroy_image(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit (0);
}

void	ft_game(t_map *map)
{
	map->nb_move = 0;
	map->get_c = 0;
	mlx_hook(map->mlx_win, 02, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 0L, close_game, map);
}

void	free_two(char *s1, char *s2)
{
	free (s1);
	free (s2);
	exit (1);
}
