/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args_to_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:34:51 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:34:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_cmdlen(t_list *node, int pipe_num)
{
	int	cnt;

	cnt = 0;
	while (node != NULL)
	{
		if (node->type == pipex)
			pipe_num -= 1;
		if ((pipe_num == 0) && (node->type == word))
			cnt += 1;
		node = node->next;
	}
	return (cnt);
}

char	**get_args(t_list *node, int pipe_num)
{
	char	**args;
	int		len;
	int		i;

	i = -1;
	len = get_cmdlen(node, pipe_num);
	args = (char **)malloc(sizeof(char *) * (len + 1));
	if (!args)
		return (NULL);
	args[len] = NULL;
	while (node != NULL)
	{
		if (node->type == pipex)
			pipe_num -= 1;
		if ((pipe_num == 0) && (node->type == word))
		{
			args[++i] = ft_strdup(node->content);
			if (!args[i])
				return (NULL);
		}
		node = node->next;
	}
	return (args);
}

char	*get_cmd(t_list *node, int pipe_num)
{
	while (node != NULL)
	{
		if (node->type == pipex)
			pipe_num -= 1;
		if ((pipe_num == 0) && (node->type == word))
			return (ft_strdup(node->content));
		node = node->next;
	}
	return (NULL);
}

int	cmd_args_to_exe(t_box *box)
{
	int	pipe_num;

	pipe_num = -1;
	while (++pipe_num < box->pipe_size)
	{
		box->exe[pipe_num]->cmd = get_cmd(box->input_split, pipe_num);
		if (!box->exe[pipe_num]->cmd)
			return (1);
		box->exe[pipe_num]->args = get_args(box->input_split, pipe_num);
		if (!box->exe[pipe_num]->args)
			return (1);
	}
	return (0);
}
