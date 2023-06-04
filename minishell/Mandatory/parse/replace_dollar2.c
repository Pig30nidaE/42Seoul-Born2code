/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:36:05 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:36:05 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_dollar_str(t_token_utils *utils, char *str, t_env *env)
{
	char	*key;

	while ((str[utils->index] != '$') && (str[utils->index] != '\'') \
	&& (str[utils->index] != '\"') && str[utils->index])
		utils->index++;
	if (utils->start == (--utils->index))
	{
		if ((utils->flag == '\'') || (utils->flag == '\"') \
		|| (str[utils->index + 1] == 0))
			return (ft_strdup("$"));
		return (NULL);
	}
	key = ft_substr(str, utils->start + 1, utils->index - utils->start);
	while (env)
	{
		if (!ft_strncmp(env->key, key, ft_strlen(key) + 1))
		{
			free(key);
			return (ft_strdup(env->value));
		}
		env = env->next;
	}
	free(key);
	return (NULL);
}

char	*replace_dollar_value(t_token_utils *utils, char *str, t_env *env)
{
	if ((48 <= str[++utils->index]) && (str[utils->index] <= 57))
		return (NULL);
	else if (str[utils->index] == '?')
		return (ft_itoa(g_error_code));
	else
		return (find_dollar_str(utils, str, env));
}
