/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:56:23 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:34:43 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_file_text(t_info *info)
{
	int	i;

	i = -1;
	while ((++i) < info->ftext_line_size)
		free(info->file_text[i]);
	free(info->file_text);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_info	info;

	check_argc(argc);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	close(fd);
	parsing(&info, argv[1]);
	check_walls(&info);
	player_info_parsing(&info);
	excuting(info);
	free_file_text(&info);
}
