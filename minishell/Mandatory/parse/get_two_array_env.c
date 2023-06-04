/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_two_array_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:33 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:33 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	key_value_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->key && env->value)
			i++;
		env = env->next;
	}
	return (i);
}

static char	*get_array_env(char *key, char *value)
{
	char	*tmp;
	char	*output;

	tmp = ft_strjoin_libft(key, "=");
	if (!tmp)
		return (NULL);
	output = ft_strjoin_libft(tmp, value);
	free(tmp);
	return (output);
}

char	**get_two_array_env(t_env *env)
{
	int		i;
	int		len;
	char	**output;

	i = -1;
	len = key_value_len(env);
	output = (char **)malloc(sizeof(char *) * (len + 1));
	if (!output)
		return (NULL);
	output[len] = NULL;
	while (env)
	{
		if (env->key && env->value)
		{
			output[++i] = get_array_env(env->key, env->value);
			if (!output[i])
				return (NULL);
		}
		env = env->next;
	}
	return (output);
}
