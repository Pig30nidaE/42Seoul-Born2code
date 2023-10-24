/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:58:23 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:05:06 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rgb_color_init(char **rgb, t_info *info)
{
	int	j;

	j = -1;
	while (rgb[++j])
	{
		if (info->parse_type == C)
		{
			info->color.ceiling[j] = ft_atoi(rgb[j]);
			if (0 > info->color.ceiling[j] || info->color.ceiling[j] > 255)
				errno_print(INVALID_ARG);
		}
		else
		{
			info->color.floor[j] = ft_atoi(rgb[j]);
			if (0 > info->color.floor[j] || info->color.floor[j] > 255)
				errno_print(INVALID_ARG);
		}
		free(rgb[j]);
	}
	if (j != 3)
		errno_print(INVALID_ARG);
	free(rgb);
}

static void	check_is_num(char *color, int i)
{
	if (color[i] > '9' || color[i] < '0')
		errno_print(INVALID_ARG);
}

void	check_rgb_color(char *color)
{
	int	i;
	int	last_index;

	i = -1;
	while (color[++i] != ',')
	{
		if (color[i] > '9' || color[i] < '0')
			errno_print(INVALID_ARG);
	}
	if (i > 3)
		errno_print(INVALID_ARG);
	last_index = i;
	while (color[++i] != ',')
		check_is_num(color, i);
	if (i - last_index > 4)
		errno_print(INVALID_ARG);
	last_index = -1;
	while (color[++i] && (++last_index) < 3)
		check_is_num(color, i);
	if (last_index == 3 && color[i])
		errno_print(INVALID_ARG);
}
