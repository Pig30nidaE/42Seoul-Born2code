/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:28 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:16:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_box_partial(t_box **box)
{
	if (!(*box))
		return ;
	free_list(&((*box)->input_split));
	free_2d_char(&((*box)->env_save));
	free_2d_exe(&((*box)->exe));
	free_list(&((*box)->here_doc));
}

void	free_box_all(t_box **box)
{
	if (!(*box))
		return ;
	free_list(&((*box)->input_split));
	free_env(&((*box)->env));
	free_2d_char(&((*box)->env_save));
	free_2d_exe(&((*box)->exe));
	free_list(&((*box)->here_doc));
	free(*box);
}
