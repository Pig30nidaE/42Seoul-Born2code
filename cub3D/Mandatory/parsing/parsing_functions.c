/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:58:46 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:31:16 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	walls_texture_parsing(t_info *info, char *reading_text)
{
	int		i;

	i = 0;
	while (reading_text[i] == ' ')
		i++;
	if (ft_strncmp(&reading_text[i], "NO ", 3)
		&& ft_strncmp(&reading_text[i], "SO ", 3)
		&& ft_strncmp(&reading_text[i], "EA ", 3)
		&& ft_strncmp(&reading_text[i], "WE ", 3))
		errno_print(INVALID_ARG);
	i += 2;
	while (reading_text[i] == ' ')
		i++;
	check_texfile_path(info, &reading_text[i]);
	if (!info->txt_path.no && info->parse_type == N)
		info->txt_path.no = &reading_text[i];
	else if (!info->txt_path.so && info->parse_type == S)
		info->txt_path.so = &reading_text[i];
	else if (!info->txt_path.ea && info->parse_type == E)
		info->txt_path.ea = &reading_text[i];
	else if (!info->txt_path.we && info->parse_type == W)
		info->txt_path.we = &reading_text[i];
	else
		errno_print(INVALID_ARG);
}

void	ceil_floo_color_parsing(t_info *info, char *reading_text)
{
	int		i;
	char	**rgb;

	i = 0;
	while (reading_text[i] == ' ')
		i++;
	if (reading_text[i] != 'F' && reading_text[i] != 'C')
		errno_print(INVALID_ARG);
	if (reading_text[i] == 'F')
		info->color.floor_flag++;
	if (reading_text[i] == 'C')
		info->color.ceil_flag++;
	i++;
	while (reading_text[i] == ' ')
		i++;
	check_rgb_color(&reading_text[i]);
	rgb = ft_split(&reading_text[i], ',');
	rgb_color_init(rgb, info);
}

static void	map_info_init(t_info *info, int map_start, int min_map_x_start)
{
	int	map_arr_index;

	map_arr_index = -1;
	while (info->file_text[map_start] && info->parse_type == MAP
		&& map_start < info->ftext_line_size)
	{
		info->map_info.map[++map_arr_index] = (char *)ft_calloc(
				info->map_info.x_size + 1, sizeof(char));
		ft_memcpy(info->map_info.map[map_arr_index],
			&info->file_text[map_start][min_map_x_start],
			ft_strlen(info->file_text[map_start]));
		info->map_info.map[map_arr_index][info->map_info.x_size] = 0;
		map_start++;
		parser_typ_c(info, map_start);
	}
	info->map_info.map[map_arr_index + 1] = 0;
}

static void	get_map_x_y_size(int *min_map_x_start, int **i, t_info *info,
	size_t *read_size)
{
	int		flag;

	flag = 0;
	while (info->file_text[**i] && info->parse_type == MAP
		&& **i < info->ftext_line_size)
	{
		*read_size = ft_strlen(info->file_text[**i]);
		if (*read_size > (size_t)(info->map_info.x_size))
			info->map_info.x_size = *read_size;
		if (!flag)
			*min_map_x_start = *read_size;
		*read_size = 0;
		while (*read_size < (size_t)(*min_map_x_start)
			&& info->file_text[**i][*read_size] != '1')
			(*read_size)++;
		if (*read_size < (size_t)(*min_map_x_start))
			*min_map_x_start = *read_size;
		flag = 1;
		(**i)++;
		parser_typ_c(info, **i);
	}
}

void	map_info_parsing(t_info *info, int **i)
{
	int		map_start;
	size_t	read_size;
	int		min_map_x_start;
	int		map_arr_index;

	map_start = **i;
	info->map_info.x_size = 0;
	parser_typ_c(info, **i);
	get_map_x_y_size(&min_map_x_start, i, info, &read_size);
	info->map_info.y_size = **i - map_start;
	info->map_info.map = malloc(sizeof(char *) * (info->map_info.y_size + 1));
	info->map_info.x_size -= min_map_x_start;
	parser_typ_c(info, map_start);
	map_arr_index = -1;
	map_info_init(info, map_start, min_map_x_start);
}
