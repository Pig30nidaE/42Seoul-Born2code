/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 05:49:29 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 16:27:47 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_dfs(int y, int x, t_dfs_info *dfs_info, t_map_info *map_info)
{
	if (dfs_info->visited[y][x] == 'C')
		dfs_info->collect_count++;
	if (dfs_info->collect_count == map_info->collect_count)
		dfs_info->collect_flag = 1;
	if (dfs_info->visited[y][x] == 'E')
		dfs_info->exit_flag = 1;
	dfs_info->visited[y][x] = '1';
	if (is_valid_position(dfs_info->visited, y - 1, x))
		run_dfs(y - 1, x, dfs_info, map_info);
	if (is_valid_position(dfs_info->visited, y, x - 1))
		run_dfs(y, x - 1, dfs_info, map_info);
	if (is_valid_position(dfs_info->visited, y + 1, x))
		run_dfs(y + 1, x, dfs_info, map_info);
	if (is_valid_position(dfs_info->visited, y, x + 1))
		run_dfs(y, x + 1, dfs_info, map_info);
	return ;
}

int	is_valid_position(char	**visited, int check_y, int check_x)
{
	if (visited[check_y][check_x] == '1')
		return (0);
	return (1);
}
