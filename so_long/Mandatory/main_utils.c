/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:41:55 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 07:02:16 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_row_size(int fd, t_map_info *map_info)
{
	int		i;
	int		row_len;
	int		col_len;
	char	*temp;

	row_len = 0;
	col_len = 0;
	temp = get_next_line(fd);
	if (temp <= 0)
		error_exit(INVAL_ARG);
	i = -1;
	col_len = ft_strlen(temp) - 1;
	while (temp)
	{
		i = -1;
		row_len++;
		map_info->col_size = 0;
		while (temp[++i] != '\n' && temp[i])
			map_info->col_size++;
		if (col_len != map_info->col_size)
			error_exit(INVAL_ARG);
		free(temp);
		temp = get_next_line(fd);
	}
	map_info->row_size = row_len;
}

int	get_elm_count(char **map, t_map_info *map_info, char target)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while ((++i) < map_info->row_size)
	{
		j = -1;
		while ((++j) < map_info->col_size)
		{
			if (map[i][j] == target)
				count++;
		}
	}
	return (count);
}
