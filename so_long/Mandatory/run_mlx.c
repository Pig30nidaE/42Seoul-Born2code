/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:21:16 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 06:38:38 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_mlx(t_map_info *map_info)
{
	map_info->mlx.mlx = mlx_init();
	map_info->mlx.win = mlx_new_window(map_info->mlx.mlx, 32
			* map_info->col_size, 32 * map_info->row_size, "SO_LONG");
	img_init(&(map_info->mlx));
	run_img(map_info);
	run_hook(map_info);
	mlx_loop(map_info->mlx.mlx);
}
