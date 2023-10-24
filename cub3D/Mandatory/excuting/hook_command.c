/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:52 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 19:55:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_camera(double speed, t_ray *ray)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(speed) - ray->dir_y * sin(speed);
	ray->dir_y = old_dir_x * sin(speed) + ray->dir_y * cos(speed);
	ray->plane_x = ray->plane_x * cos(speed) - ray->plane_y * sin(speed);
	ray->plane_y = old_plane_x * sin(speed) + ray->plane_y * cos(speed);
}

void	move(double value_x, double value_y, t_ray *ray, t_mlx *mlx)
{
	if (mlx->map[(int)(ray->pos_x + value_x * 0.03)][(int)(ray->pos_y)] \
	!= '1')
		ray->pos_x += value_x * 0.03;
	if (mlx->map[(int)ray->pos_x][(int)(ray->pos_y + value_y * 0.03)] \
	!= '1')
		ray->pos_y += value_y * 0.03;
}
