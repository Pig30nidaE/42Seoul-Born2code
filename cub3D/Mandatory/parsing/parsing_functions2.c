/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:58:56 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 17:58:58 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	player_pos_init(int i, int j, t_info *info, int dir_flag)
{
	info->player_info.dir_flag = dir_flag;
	info->player_info.pos_x = j;
	info->player_info.pos_y = i;
}

static void	player_info_init(t_info *info, int i, int j)
{
	if (info->map_info.map[i][j] == 'N'
		|| info->map_info.map[i][j] == 'E'
			|| info->map_info.map[i][j] == 'W'
				|| info->map_info.map[i][j] == 'S')
	{
		if (info->player_info.except_flag)
			errno_print(INVALID_ARG);
		if (info->map_info.map[i][j] == 'N')
			player_pos_init(i, j, info, N);
		if (info->map_info.map[i][j] == 'S')
			player_pos_init(i, j, info, S);
		if (info->map_info.map[i][j] == 'E')
			player_pos_init(i, j, info, E);
		if (info->map_info.map[i][j] == 'W')
			player_pos_init(i, j, info, W);
		info->player_info.pos_x += 0.499999;
		info->player_info.pos_y += 0.499999;
		info->player_info.except_flag = 1;
	}
}

void	player_info_parsing(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	info->player_info.except_flag = 0;
	while ((++i) < info->map_info.y_size)
	{
		j = -1;
		while ((++j) < info->map_info.x_size)
			player_info_init(info, i, j);
	}
	if (!info->player_info.except_flag)
		errno_print(INVALID_ARG);
}
