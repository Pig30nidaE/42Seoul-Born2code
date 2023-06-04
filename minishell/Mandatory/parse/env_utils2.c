/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:11 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:12 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_key_exist(t_env *env, char *key)
{
	int	len;

	env = envfirst(env);
	while (env)
	{
		if (ft_strlen(key) > ft_strlen(env->key))
			len = ft_strlen(key);
		else
			len = ft_strlen(env->key);
		if (!ft_strncmp(env->key, key, len))
			return (1);
		env = env->next;
	}
	return (0);
}

void	env_modify_value(t_env *env, char *key, char *value)
{
	while (ft_strncmp(env->key, key, ft_strlen(key) + 1))
		env = env->next;
	free(env->value);
	env->value = ft_strndup(value, 0, ft_strlen(value));
}

int	env_size(t_env *env)
{
	int	size;

	size = 0;
	env = envfirst(env);
	while (env->next)
	{
		size++;
		env = env->next;
	}
	return (size + 1);
}
