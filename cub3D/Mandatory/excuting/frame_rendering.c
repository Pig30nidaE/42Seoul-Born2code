/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:48 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 19:55:48 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	buffer_init(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
			mlx->buffer[y][x] = 0;
	}
}

static void	map_rendering(t_mlx *mlx)
{
	raycasting(mlx);
	draw_map(mlx);
	buffer_init(mlx);
}

int	frame_rendering(t_mlx *mlx)
{
	map_rendering(mlx);
	return (0);
}
