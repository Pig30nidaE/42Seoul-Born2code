/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:56:07 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 19:56:08 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	player_pos_init(double pos1, double pos2, t_ray *ray)
{
	ray->pos_x = pos1;
	ray->pos_y = pos2;
}

static void	player_dir_init(t_ray *ray)
{
	ray->dir_x = -1.00000000;
	ray->dir_y = 0.0;
}

static void	player_plane_init(t_ray *ray)
{
	ray->plane_x = 0.0;
	ray->plane_y = 0.66;
}

static void	set_player_dir(int flag, t_ray *ray)
{
	if (flag == W)
		rotate_camera(PI / 2, ray);
	else if (flag == S)
		rotate_camera(PI, ray);
	else if (flag == E)
		rotate_camera(PI + PI / 2, ray);
}

void	player_init(int flag, double x, double y, t_ray *ray)
{
	player_pos_init(y, x, ray);
	player_plane_init(ray);
	player_dir_init(ray);
	set_player_dir(flag, ray);
}
