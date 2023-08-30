/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:04:33 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 14:17:49 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_extension(char *argv)
{
	int		i;
	char	*str;

	str = argv;
	i = 0;
	while (str[i])
		i++;
	if (ft_strcmp (&str[i - 3], "ber") != 0)
	{
		ft_printf("Error\nWrong extension\n");
		exit (1);
	}
	return ;
}

void	ft_empty_file(char *argv)
{
	int		fd;
	char	test[1];

	fd = open(argv, O_RDONLY);
	if (!read(fd, test, 1))
	{
		ft_printf("Error\nEmpty file\n");
		exit (1);
	}
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid arg\n");
		return (1);
	}
	ft_empty_file(argv[1]);
	ft_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nIssues with the file\n");
		exit (1);
	}
	if (!ft_set_map(fd, &map))
	{
		free_map_tab(&map);
		ft_printf("Issues with the map\n");
		exit (1);
	}
	ft_init_game(&map);
	return (0);
}
