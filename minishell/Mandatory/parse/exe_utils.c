/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:15 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:16 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exe	**exe_init(int size)
{
	t_exe	**exe;
	int		i;

	i = -1;
	exe = (t_exe **)malloc(sizeof(t_exe) * (size + 1));
	if (!exe)
		return (NULL);
	exe[size] = NULL;
	while (++i < size)
	{
		exe[i] = (t_exe *)malloc(sizeof(t_exe) * 1);
		exe[i]->redirect = NULL;
		exe[i]->cmd = NULL;
		exe[i]->args = NULL;
		exe[i]->infd = 0;
		exe[i]->outfd = 0;
	}
	return (exe);
}
