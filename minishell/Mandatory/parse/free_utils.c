/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:24 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:16:10 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_list(t_list **input)
{
	t_list	*node;
	t_list	*next;

	node = *input;
	if (!(*input))
		return ;
	while (node)
	{
		next = node->next;
		if (node->content)
			free(node->content);
		free(node);
		node = NULL;
		node = next;
	}
	*input = NULL;
}

void	free_env(t_env **input)
{
	t_env	*node;
	t_env	*next;

	node = *input;
	if (!(*input))
		return ;
	node = envfirst(*input);
	while (node)
	{
		next = node->next;
		if (node->key)
			free(node->key);
		if (node->value)
			free(node->value);
		free(node);
		node = NULL;
		node = next;
	}
	*input = NULL;
}

void	free_2d_char(char ***input)
{
	char	**target;

	if (!(*input))
		return ;
	target = *input;
	while (*target)
	{
		if ((*target))
			free(*target);
		target++;
	}
	free(*input);
	*input = NULL;
}

void	free_1d_exe(t_exe **input)
{
	if (!(*input))
		return ;
	free_list(&((*input)->redirect));
	if ((*input)->cmd)
		free((*input)->cmd);
	if ((*input)->args)
		free_2d_char(&((*input)->args));
	free(*input);
	*input = NULL;
}

void	free_2d_exe(t_exe ***input)
{
	t_exe	**target;

	if (!(*input))
		return ;
	target = *input;
	while (*target)
	{
		free_1d_exe(&(*target));
		target++;
	}
	free(*input);
	*input = NULL;
}
