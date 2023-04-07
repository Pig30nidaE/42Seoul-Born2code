/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:43:56 by sanghyol          #+#    #+#             */
/*   Updated: 2023/03/09 21:31:53 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_every_wall_blocked(t_map_info *map_info)
{
	int	i;

	i = -1;
	while ((++i) < map_info->col_size)
	{
		if (map_info->map[0][i] != '1' || map_info->map[map_info->row_size
			- 1][i] != '1')
			error_exit(INVAL_ARG);
	}
	i = -1;
	while ((++i) < map_info->row_size)
	{
		if (map_info->map[i][0] != '1' || map_info->map[i][map_info->col_size
			- 1] != '1')
			error_exit(INVAL_ARG);
	}
}

void	is_possible_path_exist(t_map_info *map_info)
{
	t_dfs_info	*dfs_info;
	int			i;

	i = -1;
	dfs_info = (t_dfs_info *)malloc(sizeof(t_dfs_info));
	dfs_info->visited = (char **)malloc(sizeof(char *) * map_info->row_size);
	while ((++i) < map_info->row_size)
	{
		dfs_info->visited[i] = (char *)malloc(sizeof(char)
				* map_info->col_size);
		ft_memcpy(dfs_info->visited[i], map_info->map[i], map_info->col_size);
	}
	dfs_info->collect_count = 0;
	dfs_info->collect_flag = 0;
	dfs_info->exit_flag = 0;
	run_dfs(map_info->player_y, map_info->player_x, dfs_info, map_info);
	free_map(dfs_info->visited, map_info->row_size);
	if (!(dfs_info->collect_flag) || !(dfs_info->exit_flag))
	{
		free(dfs_info);
		error_exit(INVAL_ARG);
	}
	free(dfs_info);
}

void	is_only_one_player_exit(t_map_info *map_info)
{
	int	player_count;
	int	exit_count;

	player_count = get_elm_count(map_info->map, map_info, 'P');
	exit_count = get_elm_count(map_info->map, map_info, 'E');
	if (player_count > 1 || exit_count > 1)
		error_exit(INVAL_ARG);
	if (player_count < 1 || exit_count < 1)
		error_exit(INVAL_ARG);
}

void	is_collection_exist(t_map_info *map_info)
{
	if (map_info->collect_count <= 0)
		error_exit(INVAL_ARG);
}
