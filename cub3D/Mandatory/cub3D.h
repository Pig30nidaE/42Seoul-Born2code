/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:48:05 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:27:08 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../minilibx/mlx.h"

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define INVALID_ARG 22
# define NO_SUCH_FD 2

# define N 1
# define S 2
# define W 3
# define E 4
# define F 5
# define C 6
# define MAP 7

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define DESTROY 17
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define CAMERA_RIGHT 124
# define CAMERA_LEFT 123
# define PI 3.14159265359

typedef struct s_color
{
	unsigned int			ceiling[3];
	unsigned int			floor[3];
	int						ceil_flag;
	int						floor_flag;
}			t_color;

typedef struct s_texture_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_texture_path;

typedef struct s_player_info
{
	double	pos_x;
	double	pos_y;
	int		dir_flag;
	int		except_flag;
}				t_player_info;

typedef struct s_map_info
{
	char	**map;
	int		x_size;
	int		y_size;
}			t_map_info;

typedef struct s_dfs_info
{
	int		x_dir[4];
	int		y_dir[4];
}			t_dfs_info;

typedef struct s_info
{
	char			**file_text;
	int				ftext_line_size;
	int				parse_type;
	char			*base_dir;

	t_color			color;
	t_texture_path	txt_path;
	t_map_info		map_info;
	t_player_info	player_info;
	t_dfs_info		dfs_info;
}			t_info;

typedef struct s_img_data {
	void			*img;
	unsigned int	*addr;
	unsigned int	**texture;
	unsigned int	**text_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				text_width;
	int				text_height;
}				t_img_data;

typedef struct s_dda
{
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
}	t_dda;

typedef struct s_wall_draw
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	color;
}	t_wall_draw;

typedef struct s_ray
{
	double			ray_x;
	double			ray_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			wall_dist;
}	t_ray;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	unsigned int	floor;
	unsigned int	ceil;
	int				**buffer;
	char			**map;
	t_img_data		img;
	t_ray			ray;
	t_dda			dda;
	t_wall_draw		draw;
}	t_mlx;

void	check_argc(int argc);
void	check_fd(int fd);
void	check_texfile_path(t_info *info, char *file_path);
void	rgb_color_init(char **rgb, t_info *info);
void	check_rgb_color(char *color);
void	check_walls(t_info *info);
void	errno_print(int errno);

void	parsing(t_info *info, char *file_path);
void	read_file_text(t_info *info, char *file_path);
void	parser_typ_c(t_info *info, int i);
int		get_text_lines_num(char *file_path);
void	walls_texture_parsing(t_info *info, char *reading_text);
void	ceil_floo_color_parsing(t_info *info, char *reading_text);
void	map_info_parsing(t_info *info, int **i);
void	player_info_parsing(t_info *info);

void	draw_map(t_mlx *mlx);
void	draw_wall(t_mlx *mlx, int x);

int		key_press(int keycode, t_mlx *mlx);
int		game_close(t_mlx **mlx_data);

void	raycasting(t_mlx *mlx);

int		frame_rendering(t_mlx *mlx);

void	player_init(int flag, double x, double y, t_ray *ray);

void	rotate_camera(double speed, t_ray *ray);
void	move(double dir_x, double dir_y, t_ray *ray, t_mlx *mlx);

void	mlx_struct_init(t_mlx *mlx);

void	texture_init(t_mlx *mlx, t_info info);

int		excuting(t_info info);

#endif
