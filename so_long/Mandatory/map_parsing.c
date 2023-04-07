/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:57:18 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 05:18:39 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parsing(int fd, int row_size, t_map_info *map_info)
{
	char	**map;
	int		y;
	int		x;

	map = (char **)malloc(sizeof(char *) * (row_size + 1));
	map[row_size] = 0;
	y = -1;
	while ((++y) < row_size)
	{
		map[y] = get_next_line(fd);
		x = -1;
		while (map[y][++x] != '\n' && map[y][x] != 0)
			get_map_elm_info(map, map_info, y, x);
	}
	map_info->collect_count = get_elm_count(map, map_info, 'C');
	map_info->move_count = 0;
	return (map);
}

void	get_map_elm_info(char **map, t_map_info *map_info, int y, int x)
{
	if (map[y][x] == 'P')
	{
		map_info->player_y = y;
		map_info->player_x = x;
	}
	else if (map[y][x] == 'C')
	{
		map_info->collect_y = y;
		map_info->collect_x = x;
	}
	else if (map[y][x] == 'E')
	{
		map_info->exit_y = y;
		map_info->exit_x = x;
	}
}
