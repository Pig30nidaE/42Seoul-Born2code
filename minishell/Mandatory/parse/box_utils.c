/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:34:44 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:34:46 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_box	*init_box(void)
{
	t_box	*box;

	box = (t_box *)malloc(sizeof(t_box));
	if (!box)
		return (NULL);
	box->input_split = NULL;
	box->env = NULL;
	box->exe = NULL;
	box->pipe_size = 0;
	box->here_doc = NULL;
	return (box);
}
