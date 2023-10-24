/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:55 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:34:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	free_addr_text(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(mlx->img.texture[i]);
		free(mlx->img.text_addr[i]);
	}
	free(mlx->img.texture);
	free(mlx->img.text_addr);
	i = -1;
	while (++i < SCREEN_HEIGHT)
		free(mlx->buffer[i]);
	free(mlx->buffer);
}

int	game_close(t_mlx **mlx_data)
{
	mlx_destroy_window((*mlx_data)->mlx, (*mlx_data)->win);
	exit(0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	t_ray	*ray;

	ray = &mlx->ray;
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free_addr_text(mlx);
		exit(0);
	}
	if (keycode == CAMERA_LEFT)
		rotate_camera(0.03, ray);
	if (keycode == CAMERA_RIGHT)
		rotate_camera(-0.03, ray);
	if (keycode == UP)
		move(ray->dir_x, ray->dir_y, ray, mlx);
	if (keycode == DOWN)
		move(-(ray->dir_x), -(ray->dir_y), ray, mlx);
	if (keycode == RIGHT)
		move(ray->plane_x, ray->plane_y, ray, mlx);
	if (keycode == LEFT)
		move(-(ray->plane_x), -(ray->plane_y), ray, mlx);
	return (0);
}
