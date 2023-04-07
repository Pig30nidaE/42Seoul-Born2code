/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:51:29 by sanghyol          #+#    #+#             */
/*   Updated: 2023/03/09 21:35:03 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_map_info	*map_info;

	if (argc != 2)
		error_exit(INVAL_ARG);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(NO_SUCH_FD);
	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	get_map_row_size(fd, map_info);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_info->map = map_parsing(fd, map_info->row_size, map_info);
	close(fd);
	is_only_one_player_exit(map_info);
	is_every_wall_blocked(map_info);
	is_collection_exist(map_info);
	is_possible_path_exist(map_info);
	run_mlx(map_info);
}
