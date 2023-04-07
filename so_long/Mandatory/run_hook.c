/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:25:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 06:52:16 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_hook(t_map_info *map_info)
{
	mlx_hook(map_info->mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, map_info);
	mlx_hook(map_info->mlx.win, X_EVENT_DESTROY, 0, &on_click, map_info);
}

int	key_press(int keycode, t_map_info *map_info)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W)
	{
		if (keycode == KEY_W)
			move_w(map_info);
		else if (keycode == KEY_S)
			move_s(map_info);
		else if (keycode == KEY_A)
			move_a(map_info);
		else
			move_d(map_info);
	}
	else
	{
		if (keycode == KEY_ESC)
			exit(1);
	}
	return (0);
}

int	on_click(t_map_info *map_info)
{
	(void)map_info;
	exit(0);
	return (0);
}
