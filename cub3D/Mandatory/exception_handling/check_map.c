/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:02:13 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 18:56:30 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	dir_init(t_info *info)
{
	info->dfs_info.x_dir[0] = 0;
	info->dfs_info.x_dir[1] = 1;
	info->dfs_info.x_dir[2] = 0;
	info->dfs_info.x_dir[3] = -1;
	info->dfs_info.y_dir[0] = -1;
	info->dfs_info.y_dir[1] = 0;
	info->dfs_info.y_dir[2] = 1;
	info->dfs_info.y_dir[3] = 0;
}

static void	check_corner(t_info *info, int x, int y, int i)
{
	if (0 <= x + info->dfs_info.x_dir[i]
		&& x + info->dfs_info.x_dir[i] < info->map_info.x_size
		&& 0 <= y + info->dfs_info.y_dir[i]
		&& y + info->dfs_info.y_dir[i] < info->map_info.y_size)
	{
		if (info->map_info.map[y][x] != '1'
			&& info->map_info.map[y][x] != ' '
				&& info->map_info.map[y][x] != 0)
			errno_print(INVALID_ARG);
	}	
}

static void	check_border(t_info *info, int x, int y, int i)
{
	if (info->map_info.map[y + info->dfs_info.y_dir[i]][x
		+ info->dfs_info.x_dir[i]] != '1'
		&& info->map_info.map[y + info->dfs_info.y_dir[i]][x
			+ info->dfs_info.x_dir[i]] != ' '
			&& info->map_info.map[y + info->dfs_info.y_dir[i]][x
				+ info->dfs_info.x_dir[i]] != 0)
		errno_print(INVALID_ARG);
}

static void	check_zero_area(t_info *info, int x, int y, int i)
{
	if (info->map_info.map[y + info->dfs_info.y_dir[i]][x
		+ info->dfs_info.x_dir[i]] == ' '
		|| info->map_info.map[y + info->dfs_info.y_dir[i]][x
			+ info->dfs_info.x_dir[i]] == 0)
		errno_print(INVALID_ARG);
}

void	check_walls(t_info *info)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	dir_init(info);
	while ((++y) < info->map_info.y_size)
	{
		x = -1;
		while ((++x) < info->map_info.x_size)
		{
			i = -1;
			while ((++i) < 4)
			{
				if (y == 0 || y == info->map_info.y_size - 1
					|| x == 0 || x == info->map_info.x_size - 1)
					check_corner(info, x, y, i);
				else if (info->map_info.map[y][x] == ' '
					|| !info->map_info.map[y][x])
					check_border(info, x, y, i);
				else if (info->map_info.map[y][x] == '0')
					check_zero_area(info, x, y, i);
			}
		}
	}
}
