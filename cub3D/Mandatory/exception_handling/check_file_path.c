/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:57:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 18:57:03 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_texfile_path(t_info *info, char *file_path)
{
	int		temp_fd;

	file_path = ft_strjoin(info->base_dir, file_path);
	temp_fd = open(file_path, O_RDONLY);
	free(file_path);
	if (temp_fd < 0)
		errno_print(INVALID_ARG);
	else
		close(temp_fd);
}
