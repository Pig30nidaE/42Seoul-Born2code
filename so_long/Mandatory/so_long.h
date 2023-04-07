/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:43:43 by sanghyol          #+#    #+#             */
/*   Updated: 2023/03/13 18:17:02 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define NO_SUCH_FD 2
# define INVAL_ARG 22

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img
{
	void	*walls;
	void	*tile;
	void	*player;
	void	*exit;
	void	*collect;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_mlx;

typedef struct s_map_info
{
	int		row_size;
	int		col_size;
	int		player_x;
	int		player_y;
	int		collect_x;
	int		collect_y;
	int		collect_count;
	int		exit_x;
	int		exit_y;
	int		move_count;
	char	**map;
	t_mlx	mlx;
}			t_map_info;

typedef struct s_dfs_info
{
	char	**visited;
	int		collect_count;
	int		collect_flag;
	int		exit_flag;
}			t_dfs_info;

void		*ft_memcpy(void *dst, const void *src, size_t n);

char		**map_parsing(int fd, int row_size, t_map_info *map_info);
void		get_map_row_size(int fd, t_map_info *map_info);
void		error_exit(int err_num);
void		is_every_wall_blocked(t_map_info *map_info);
void		is_only_one_player_exit(t_map_info *map_info);
void		is_possible_path_exist(t_map_info *map_info);
void		is_collection_exist(t_map_info *map_info);
void		get_map_elm_info(char **map, t_map_info *map_info, int y, int x);
void		run_dfs(int y, int x, t_dfs_info *dfs_info, t_map_info *map_info);
int			is_valid_position(char **visited, int check_y, int check_x);
int			get_elm_count(char **map, t_map_info *map_info, char target);
void		free_map(char **map, int row_size);

void		run_mlx(t_map_info *map_info);
void		run_img(t_map_info *map_info);
void		img_init(t_mlx *mlx);
void		determine_img(char map, t_mlx *mlx, int i, int j);
void		run_hook(t_map_info *map_info);
int			key_press(int keycode, t_map_info *map_info);
void		move_w(t_map_info *map_info);
void		move_a(t_map_info *map_info);
void		move_s(t_map_info *map_info);
void		move_d(t_map_info *map_info);
int			on_click(t_map_info *map_info);

#endif