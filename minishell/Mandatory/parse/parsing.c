/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:51 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:51 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(char *str, t_box *box)
{
	box->env_save = get_two_array_env(box->env);
	box->input_split = lstnew(NULL, 0);
	if (!make_token(str, box->input_split))
		return (1);
	if (syntax_alaysis(box))
		return (1);
	cmd_args_to_exe(box);
	return (0);
}
