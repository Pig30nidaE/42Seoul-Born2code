/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:56:14 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:17:17 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	texture_make_img(t_mlx *mlx, t_info info)
{
	mlx->img.texture[0] = mlx_xpm_file_to_image(mlx->mlx,
			info.txt_path.ea, &(mlx->img.text_width), &(mlx->img.text_height));
	mlx->img.texture[1] = mlx_xpm_file_to_image(mlx->mlx,
			info.txt_path.we, &(mlx->img.text_width), &(mlx->img.text_height));
	mlx->img.texture[2] = mlx_xpm_file_to_image(mlx->mlx,
			info.txt_path.so, &(mlx->img.text_width), &(mlx->img.text_height));
	mlx->img.texture[3] = mlx_xpm_file_to_image(mlx->mlx,
			info.txt_path.no, &(mlx->img.text_width), &(mlx->img.text_height));
}

static void	texture_get_addr(t_img_data *img)
{
	img->text_addr[0] = (unsigned int *)mlx_get_data_addr(img->texture[0], \
	&img->bits_per_pixel, &img->line_length, &img->endian);
	img->text_addr[1] = (unsigned int *)mlx_get_data_addr(img->texture[1], \
	&img->bits_per_pixel, &img->line_length, &img->endian);
	img->text_addr[2] = (unsigned int *)mlx_get_data_addr(img->texture[2], \
	&img->bits_per_pixel, &img->line_length, &img->endian);
	img->text_addr[3] = (unsigned int *)mlx_get_data_addr(img->texture[3], \
	&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	texture_init(t_mlx *mlx, t_info info)
{
	unsigned int	**text;
	unsigned int	**addr;
	int				i;

	i = -1;
	text = (unsigned int **)malloc(sizeof(unsigned int *) * 4);
	addr = (unsigned int **)malloc(sizeof(unsigned int *) * 4);
	mlx->img.texture = text;
	mlx->img.text_addr = addr;
	texture_make_img(mlx, info);
	texture_get_addr(&mlx->img);
}
