/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:00:32 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 06:32:44 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_map_info *map_info)
{
	if (map_info->map[map_info->player_y - 1][map_info->player_x] == '1')
		return ;
	if (map_info->map[map_info->player_y - 1][map_info->player_x] == 'C')
		map_info->collect_count--;
	if (map_info->map[map_info->player_y - 1][map_info->player_x] == 'E'
		&& !map_info->collect_count)
		exit(0);
	map_info->map[map_info->player_y][map_info->player_x] = '0';
	if (map_info->map[map_info->exit_y][map_info->exit_x] != 'P')
		map_info->map[map_info->exit_y][map_info->exit_x] = 'E';
	map_info->player_y--;
	map_info->map[map_info->player_y][map_info->player_x] = 'P';
	ft_printf("%d\n", ++(map_info->move_count));
	run_img(map_info);
}

void	move_a(t_map_info *map_info)
{
	if (map_info->map[map_info->player_y][map_info->player_x - 1] == '1')
		return ;
	if (map_info->map[map_info->player_y][map_info->player_x - 1] == 'C')
		map_info->collect_count--;
	if (map_info->map[map_info->player_y][map_info->player_x - 1] == 'E'
		&& !map_info->collect_count)
		exit(0);
	map_info->map[map_info->player_y][map_info->player_x] = '0';
	if (map_info->map[map_info->exit_y][map_info->exit_x] != 'P')
		map_info->map[map_info->exit_y][map_info->exit_x] = 'E';
	map_info->player_x--;
	map_info->map[map_info->player_y][map_info->player_x] = 'P';
	ft_printf("%d\n", ++(map_info->move_count));
	run_img(map_info);
}

void	move_s(t_map_info *map_info)
{
	if (map_info->map[map_info->player_y + 1][map_info->player_x] == '1')
		return ;
	if (map_info->map[map_info->player_y + 1][map_info->player_x] == 'C')
		map_info->collect_count--;
	if (map_info->map[map_info->player_y + 1][map_info->player_x] == 'E'
		&& !map_info->collect_count)
		exit(0);
	map_info->map[map_info->player_y][map_info->player_x] = '0';
	if (map_info->map[map_info->exit_y][map_info->exit_x] != 'P')
		map_info->map[map_info->exit_y][map_info->exit_x] = 'E';
	map_info->player_y++;
	map_info->map[map_info->player_y][map_info->player_x] = 'P';
	ft_printf("%d\n", ++(map_info->move_count));
	run_img(map_info);
}

void	move_d(t_map_info *map_info)
{
	if (map_info->map[map_info->player_y][map_info->player_x + 1] == '1')
		return ;
	if (map_info->map[map_info->player_y][map_info->player_x + 1] == 'C')
		map_info->collect_count--;
	if (map_info->map[map_info->player_y][map_info->player_x + 1] == 'E'
		&& !map_info->collect_count)
		exit(0);
	map_info->map[map_info->player_y][map_info->player_x] = '0';
	if (map_info->map[map_info->exit_y][map_info->exit_x] != 'P')
		map_info->map[map_info->exit_y][map_info->exit_x] = 'E';
	map_info->player_x++;
	map_info->map[map_info->player_y][map_info->player_x] = 'P';
	ft_printf("%d\n", ++(map_info->move_count));
	run_img(map_info);
}
