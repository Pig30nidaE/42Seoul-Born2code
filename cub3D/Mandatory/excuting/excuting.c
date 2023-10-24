/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excuting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:55:44 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:17:45 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

unsigned int	trans_rgb(unsigned int *rgb)
{
	unsigned int	color;

	color = 0;
	color += rgb[0] * 256 * 256;
	color += rgb[1] * 256;
	color += rgb[2];
	return (color);
}

int	excuting(t_info info)
{
	t_mlx	mlx;
	int		i;
	int		**buffer;

	buffer = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT);
	i = -1;
	while ((++i) < SCREEN_HEIGHT)
		buffer[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
	mlx.buffer = buffer;
	mlx.map = info.map_info.map;
	mlx.ceil = trans_rgb(info.color.ceiling);
	mlx.floor = trans_rgb(info.color.floor);
	player_init(info.player_info.dir_flag, info.player_info.pos_x,
		info.player_info.pos_y, &mlx.ray);
	mlx_struct_init(&mlx);
	texture_init(&mlx, info);
	mlx_hook(mlx.win, DESTROY, 0, game_close, &mlx);
	mlx_hook(mlx.win, 2, 1, key_press, &mlx);
	mlx_loop_hook(mlx.mlx, frame_rendering, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
