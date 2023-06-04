/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:44:17 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*envnew(char *key, char *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	if (!key)
		node->key = NULL;
	else
		node->key = key;
	if (!value)
		node->value = NULL;
	else
		node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->order = 0;
	node->built_last_env_flag = 0;
	return (node);
}

char	*get_value(char *str, int start)
{
	char	*value;
	int		i;
	int		len;

	i = -1;
	len = start;
	while (str[len])
		len++;
	len -= start;
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	value[len] = '\0';
	while ((++i) < len)
	{
		value[i] = str[start];
		start++;
	}
	return (value);
}

char	*get_key(char *str, int len)
{
	char	*key;
	int		i;

	i = -1;
	key = (char *)malloc(sizeof(char) * (len + 1));
	if (!key)
		return (NULL);
	key[len] = '\0';
	while ((++i) < len)
		key[i] = str[i];
	return (key);
}

static t_env	*sort_env(t_env *loop)
{
	int		i;
	t_env	*cmp_node;
	t_env	*head;

	i = -1;
	head = envfirst(loop);
	loop = head;
	while (loop)
	{
		cmp_node = head;
		while (cmp_node)
		{
			if (ft_ascii_cmp(loop->key, cmp_node->key) >= 0)
				loop->order++;
			if (!(cmp_node->next))
				break ;
			cmp_node = cmp_node->next;
		}
		if (!(loop->next))
			break ;
		loop = loop->next;
	}
	loop->built_last_env_flag = 1;
	return (head);
}

t_env	*set_envp(char **envp)
{
	t_env	*loop;
	int		i;
	int		tmp;

	i = 0;
	tmp = ft_strchr_index(envp[i], '=');
	loop = envnew(get_key(envp[i], tmp), get_value(envp[i], tmp + 1));
	if (!loop)
		return (NULL);
	while (envp[(++i)] != NULL)
	{
		tmp = ft_strchr_index(envp[i], '=');
		loop->next = envnew(get_key(envp[i], tmp), get_value(envp[i], tmp + 1));
		loop->next->prev = loop;
		if (!(loop->next))
			return (NULL);
		loop = loop->next;
	}
	return (sort_env(loop));
}
