/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:47:09 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 13:50:21 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_char(char *str)
{
	free(str);
	exit (1);
}

void	free_map_cpy(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_cpy[i])
	{
		free(map->map_cpy[i]);
		i++;
	}
	free(map->map_cpy);
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
	map->count_c = 0;

	if (cpy[y][x] == '1' || cpy[y][x] == 'V' || cpy[y][x] == 'E')
		return ;
	if (cpy[y][x] == 'C')
		map->count_c++;
	cpy[y][x] = 'V';
	ft_coins_error(map, cpy, y, x + 1);
	ft_coins_error(map, cpy, y, x - 1);
	ft_coins_error(map, cpy, y + 1, x);
	ft_coins_error(map, cpy, y - 1, x);
}

int	ft_error2(t_map *map)
{
	t_pos	exit;

	exit.x = 1;
	exit.y = 1;

	if (!ft_exit_error(map->map_cpy, exit.y, exit.x))
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	return (1);
}
