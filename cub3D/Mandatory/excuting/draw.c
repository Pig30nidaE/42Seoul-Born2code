/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:22 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 19:55:23 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_init_first(t_wall_draw *draw, t_dda *dda, t_ray *ray)
{
	draw->line_height = (int)(SCREEN_HEIGHT / ray->wall_dist);
	draw->draw_start = -draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->draw_end >= SCREEN_HEIGHT)
		draw->draw_end = SCREEN_HEIGHT - 1;
	if (dda->side == 1 && ray->ray_y > 0)
		draw->tex_num = 0;
	else if (dda->side == 1 && ray->ray_y < 0)
		draw->tex_num = 1;
	else if (dda->side == 0 && ray->ray_x > 0)
		draw->tex_num = 2;
	else if (dda->side == 0 && ray->ray_x < 0)
		draw->tex_num = 3;
	if (dda->side == 0)
		draw->wall_x = ray->pos_y + ray->wall_dist * ray->ray_y;
	else
		draw->wall_x = ray->pos_x + ray->wall_dist * ray->ray_x;
}

static void	draw_init_second(t_wall_draw *draw, t_dda *dda, t_ray *ray)
{
	draw->wall_x -= floor((draw->wall_x));
	draw->tex_x = (int)(draw->wall_x * (double)(TEX_WIDTH));
	if (dda->side == 0 && ray->ray_x > 0)
		draw->tex_x = TEX_WIDTH - draw->tex_x - 1;
	if (dda->side == 1 && ray->ray_y < 0)
		draw->tex_x = TEX_WIDTH - draw->tex_x - 1;
	draw->step = 1.0 * TEX_HEIGHT / draw->line_height;
	draw->tex_pos = (draw->draw_start - SCREEN_HEIGHT / 2 \
	+ draw->line_height / 2) * draw->step;
}

static void	put_wall_color(t_wall_draw *draw, t_dda *dda, t_mlx *mlx, int x)
{
	int	y;

	y = -1;
	while (++y < SCREEN_HEIGHT / 2)
		mlx->buffer[y][x] = mlx->ceil;
	y = SCREEN_HEIGHT / 2;
	while (++y < SCREEN_HEIGHT)
		mlx->buffer[y][x] = mlx->floor;
	y = draw->draw_start;
	while (y <= draw->draw_end)
	{
		draw->tex_y = (int)draw->tex_pos & (TEX_HEIGHT - 1);
		draw->tex_pos += draw->step;
		draw->color = mlx->img.text_addr[draw->tex_num][TEX_HEIGHT \
		* draw->tex_y + draw->tex_x];
		if (dda->side == 1)
			draw->color = (draw->color >> 1) & 8355711;
		mlx->buffer[y][x] = draw->color;
		y++;
	}
}

void	draw_wall(t_mlx *mlx, int x)
{
	t_dda		*dda;
	t_ray		*ray;
	t_wall_draw	*draw;

	dda = &mlx->dda;
	ray = &mlx->ray;
	draw = &mlx->draw;
	draw_init_first(draw, dda, ray);
	draw_init_second(draw, dda, ray);
	put_wall_color(draw, dda, mlx, x);
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT)
			mlx->img.addr[SCREEN_WIDTH * j + i] = mlx->buffer[j][i];
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
