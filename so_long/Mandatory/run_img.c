/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:24:55 by sanghyol          #+#    #+#             */
/*   Updated: 2023/03/05 21:02:12 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_img(t_map_info *map_info)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(map_info->mlx.mlx, map_info->mlx.win);
	while ((++i) < map_info->row_size)
	{
		j = -1;
		while ((++j) < map_info->col_size)
			determine_img(map_info->map[i][j], &(map_info->mlx), i, j);
	}
}

void	img_init(t_mlx *mlx)
{
	mlx->img.collect = mlx_xpm_file_to_image(mlx->mlx, "./Assets/Map/item.xpm",
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.exit = mlx_xpm_file_to_image(mlx->mlx, "./Assets/Map/exit.xpm",
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.tile = mlx_xpm_file_to_image(mlx->mlx, "./Assets/Map/tiles.xpm",
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.walls = mlx_xpm_file_to_image(mlx->mlx, "./Assets/Map/wall.xpm",
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.player = mlx_xpm_file_to_image(mlx->mlx, "./Assets/Map/player.xpm",
			&(mlx->img.width), &(mlx->img.height));
}

void	determine_img(char map, t_mlx *mlx, int i, int j)
{
	if (map == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.tile, j * 32, i
			* 32);
	else if (map == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.walls, j * 32, i
			* 32);
	else if (map == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.exit, j * 32, i
			* 32);
	else if (map == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.collect, j * 32, i
			* 32);
	else if (map == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.tile, j * 32, i
			* 32);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.player, j * 32, i
			* 32);
	}
}
