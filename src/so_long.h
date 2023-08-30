/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:15:25 by cxu               #+#    #+#             */
/*   Updated: 2023/08/30 14:40:03 by cxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/Libft/libft.h"
# include "../includes/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <mlx.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*wall;
	void	*ground;
	void	*exit;
	void	*chest;
	char	**map_tab;
	char	**map_cpy;
	char	**map_cpy_2;
	int		width;
	int		height;
	int		nb_c;
	int		get_c;
	int		nb_p;
	int		p_x;
	int		p_y;
	int		nb_e;
	int		nb_move;
	int		count_c;
	int		start_y;
	int		start_x;
}			t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

/* read_map */

char	**ft_set_map(int fd, t_map *map);
void	ft_get_map_stat(t_map *map);
void	ft_read_map(int fd, t_map *map);
char	*ft_strjoin_so_long(char *s1, char *s2);
int		ft_strlen_so_long(char *str);

/* error */

int		ft_error(t_map *map);
int		ft_wall_error(t_map *map, int len);
int		ft_form_error(t_map *map, int len);
int		ft_entity_error(t_map *map);
int		ft_char_error(t_map *map);
int		ft_exit_error(char **cpy, int y, int x);
void	ft_free_char(char *str);
void	free_map_cpy(t_map *map);
int		ft_error2(t_map *map);
void	ft_coins_error(t_map *map, char **cpy, int y, int x);

/* init_game */

void	ft_set_img(t_map *map);
void	ft_set_item(t_map *map, t_pos pos);
void	ft_init_game(t_map *map);
void	ft_init_img(t_map *map);

/* game */

void	ft_game(t_map *map);
int		close_game(t_map *map);
void	destroy_image(t_map *map);
void	free_map_tab(t_map *map);
void	free_two(char *s1, char *s2);

/* move */

int		key_hook(int keycode, t_map *map);
void	move_a(int keycode, t_map *map);
void	move_s(int keycode, t_map *map);
void	move_d(int keycode, t_map *map);
void	move_w(int keycode, t_map *map);

/* set_textures */

void	set_char(int keycode, t_map *map);
void	set_ground(t_map *map, int y, int x);
int		check_exit(t_map *map, int y, int x);
void	check_item(t_map *map, int y, int x);

#endif