/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_to_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:57 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:57 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_redirect_args(t_list *input)
{
	while (input != NULL)
	{
		if (((input->type == infile) || (input->type == outfile) \
		|| (input->type == append) || input->type == here_doc))
		{
			if (!input->next)
				return (print_syntax_error_int("newline"));
			else if (!(input->next->type == word))
				return (print_syntax_error_int(input->next->content));
		}
		input = input->next;
	}
	return (1);
}

static t_list	*get_here_doc(t_list *node)
{
	t_list	*output;

	output = NULL;
	while (node != NULL)
	{
		if (node->type == here_doc)
		{
			if (!node->next)
				return (print_syntax_error_null("newline"));
			else if (!(node->next->type == word))
				return (print_syntax_error_null(node->next->content));
			else
				lstadd_back(&output, lstnew(\
				ft_strdup(node->next->content), here_doc));
		}
		node = node->next;
	}
	if (!output)
		output = lstnew(NULL, 0);
	return (output);
}

static t_list	*get_redirect(t_list *in, int flag)
{
	t_list	*o;

	o = NULL;
	while (in != NULL)
	{
		if (in->type == pipex)
			flag -= 1;
		if ((0 == flag) && ((in->type == infile) || (in->type == outfile) \
		|| (in->type == append) || in->type == here_doc))
		{
			if (!in->next)
				return (print_syntax_error_null("newline"));
			else if (!(in->next->type == word))
				return (print_syntax_error_null(in->next->content));
			else
			{
				lstadd_back(&o, lstnew(ft_strdup(in->next->content), in->type));
				in->next->type = redirect_arg;
			}
		}
		in = in->next;
	}
	if (!o)
		o = lstnew(NULL, 0);
	return (o);
}

int	redirect_to_exe(t_box *box)
{
	int	i;

	i = -1;
	if (!check_redirect_args(box->input_split))
		return (1);
	box->here_doc = get_here_doc(box->input_split);
	if (!box->here_doc)
		return (1);
	while (++i < box->pipe_size)
	{
		box->exe[i]->redirect = get_redirect(box->input_split, i);
		if (!box->exe[i]->redirect)
			return (1);
	}
	return (0);
}
