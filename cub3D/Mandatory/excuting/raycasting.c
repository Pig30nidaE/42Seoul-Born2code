/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:56:11 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 19:56:12 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	perform_dda(t_ray *ray, t_dda *dda, t_mlx *mlx)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			ray->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			ray->map_y += dda->step_y;
			dda->side = 1;
		}
		if (mlx->map[ray->map_x][ray->map_y] == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		ray->wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		ray->wall_dist = dda->side_dist_y - dda->delta_dist_y;
}

static void	set_ray_direction(t_dda *dda, t_ray *ray)
{
	if (ray->ray_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (ray->pos_x - ray->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * dda->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (ray->pos_y - ray->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * dda->delta_dist_y;
	}
}

static void	raycasting_init(t_ray *ray, t_dda *dda, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	if (ray->ray_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / ray->ray_x);
	if (ray->ray_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / ray->ray_y);
	dda->hit = 0;
}

void	raycasting(t_mlx *mlx)
{
	int		x;
	t_dda	*dda;
	t_ray	*ray;

	dda = &mlx->dda;
	ray = &mlx->ray;
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		raycasting_init(ray, &mlx->dda, x);
		set_ray_direction(dda, ray);
		perform_dda(ray, dda, mlx);
		draw_wall(mlx, x);
	}
}
