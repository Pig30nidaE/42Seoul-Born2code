/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:59:06 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:31:41 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	txt_path_other_var_init(t_info *info, int *i, int *flag)
{
	info->base_dir = "/Users/sanghyol/cub3D/";
	*i = -1;
	*flag = 0;
	info->txt_path.ea = 0;
	info->txt_path.we = 0;
	info->txt_path.so = 0;
	info->txt_path.no = 0;
}

static int	parsing_by_typ(t_info *info, int *flag, int *i)
{
	int	return_status;

	return_status = 0;
	if (info->parse_type == N || info->parse_type == S
		|| info->parse_type == E || info->parse_type == W)
	{
		walls_texture_parsing(info, info->file_text[*i]);
		(*flag)++;
		return_status = 1;
	}
	else if (info->parse_type == C || info->parse_type == F)
	{
		ceil_floo_color_parsing(info, info->file_text[*i]);
		(*flag)++;
		return_status = 1;
	}
	else if (info->parse_type == MAP)
	{
		if ((*flag) == 7)
			errno_print(INVALID_ARG);
		map_info_parsing(info, &i);
		(*flag)++;
		return_status = 1;
	}
	return (return_status);
}

void	parsing(t_info *info, char *file_path)
{
	int	i;
	int	flag;

	read_file_text(info, file_path);
	txt_path_other_var_init(info, &i, &flag);
	info->color.ceil_flag = 0;
	info->color.floor_flag = 0;
	while ((++i) < info->ftext_line_size)
	{
		parser_typ_c(info, i);
		if (info->parse_type == MAP && flag < 6)
			errno_print(INVALID_ARG);
		if (!(parsing_by_typ(info, &flag, &i)))
			continue ;
	}
	if (info->color.ceil_flag != 1 || info->color.floor_flag != 1)
		errno_print(INVALID_ARG);
}

void	read_file_text(t_info *info, char *file_path)
{
	char	*gnl_rst;
	int		fd;
	int		i;

	info->ftext_line_size = get_text_lines_num(file_path);
	fd = open(file_path, O_RDONLY);
	gnl_rst = get_next_line(fd);
	info->file_text = (char **)malloc(sizeof(char *) * (info->ftext_line_size));
	i = -1;
	while (gnl_rst)
	{
		info->file_text[++i] = ft_strtrim(gnl_rst, "\n");
		gnl_rst = get_next_line(fd);
	}
	close(fd);
}
