/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:59:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 17:59:03 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	parser_typ_init(t_info *info, int i, int index)
{
	if (info->file_text[i][0] == 'N')
		info->parse_type = N;
	else if (info->file_text[i][0] == 'S')
		info->parse_type = S;
	else if (info->file_text[i][0] == 'W')
		info->parse_type = W;
	else if (info->file_text[i][0] == 'E')
		info->parse_type = E;
	else if (info->file_text[i][0] == 'F')
		info->parse_type = F;
	else if (info->file_text[i][0] == 'C')
		info->parse_type = C;
	else if (info->file_text[i][0] == ' ' || info->file_text[i][0] == '1')
	{
		while (info->file_text[i][index] && info->file_text[i][index] == ' ')
			index++;
		if (info->file_text[i][index] == '1')
			info->parse_type = MAP;
	}
	else if (!info->file_text[i][0])
		info->parse_type = 0;
	else
		errno_print(INVALID_ARG);
}

void	parser_typ_c(t_info *info, int i)
{
	if (i >= info->ftext_line_size)
	{
		info->parse_type = 0;
		return ;
	}
	parser_typ_init(info, i, 0);
}

int	get_text_lines_num(char *file_path)
{
	int		fd;
	int		lines;
	char	*gnl;

	fd = open(file_path, O_RDONLY);
	lines = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		lines++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (lines);
}
