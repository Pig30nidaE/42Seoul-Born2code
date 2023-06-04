/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_syntax_alaysis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:36:54 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:36:55 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	input_syntax_alaysis(t_box *box)
{
	t_list	*node;

	node = box->input_split->next;
	while (node != NULL)
	{
		if (check_dollar(node->content))
			node->type = check_dollar(node->content);
		else if (check_syntax_quote(node->content))
		{
			node->content = cut_quote(node->content);
			node->type = word;
		}
		else if (check_syntax_redirect(node->content))
			node->type = check_syntax_redirect(node->content);
		else if (check_syntax_pipe(node->content))
			node->type = pipex;
		else
			node->type = word;
		node = node->next;
	}
}

int	syntax_alaysis(t_box *box)
{
	input_syntax_alaysis(box);
	convert_dollar_sign(box);
	(box)->pipe_size = count_pipe(box);
	if ((box)->pipe_size == 0)
		return (1);
	(box)->exe = exe_init((box)->pipe_size);
	if (redirect_to_exe(box))
		return (1);
	return (0);
}
