/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghakl <donghakl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:09:01 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:30:28 by donghakl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*envfirst(t_env *env)
{
	if (!(env))
		return (0);
	while (env->prev)
		env = env->prev;
	return (env);
}

t_env	*envlast(t_env *env)
{
	if (!(env))
		return (0);
	while (env->next)
		env = env->next;
	return (env);
}

void	env_addback(t_env *env, char *key, char *value)
{
	t_env	*to_add_next;

	if (!key)
		return ;
	else
	{
		env = envlast(env);
		while (ft_ascii_cmp(key, env->key) <= 0 && !(env->built_last_env_flag))
			env = env->prev;
		to_add_next = env->next;
		env->next = envnew(key, value);
		env->next->prev = env;
		env->next->next = to_add_next;
	}
}

void	envdel(t_env *env)
{
	if (env->prev)
		env->prev->next = env->next;
	if (env->next)
		env->next->prev = env->prev;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

char	*get_env_by_key(t_env *env, char *key)
{
	env = envfirst(env);
	while (env->next)
	{
		if (!ft_strncmp(key, env->key, ft_strlen(key) + 1))
			return (env->value);
		env = env->next;
	}
	return (0);
}
