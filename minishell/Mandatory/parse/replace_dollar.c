/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:36:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:44:46 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*contact_dollar(char *str, t_env *env, t_token_utils *utils)
{
	char	*convert;

	utils->start = utils->index;
	convert = replace_dollar_value(utils, str, env);
	return (convert);
}

static void	make_str(t_token_utils *utils, char *in, t_env *env, char **out)
{
	char	*str;
	char	*tmp;

	if (utils->flag != '\'' && in[utils->index] == '$')
	{
		str = contact_dollar(in, env, utils);
		tmp = ft_strjoin_libft(*out, str);
		if (str)
			free(str);
		free(*out);
		*out = tmp;
		tmp = NULL;
	}
	else
	{
		tmp = ft_charjoin(*out, in[utils->index]);
		free(*out);
		*out = tmp;
		tmp = NULL;
	}
}

static char	*convert_dollar(char *before, t_env *env)
{
	t_token_utils	utils;
	char			*output;

	output = ft_strdup("");
	utils.flag = 0;
	utils.index = -1;
	if (!before)
		return (NULL);
	while (before[++(utils.index)])
	{
		if (!check_quotes(before[utils.index], &utils.flag))
			continue ;
		if (ft_isprint(before[utils.index]) \
		&& (utils.flag != before[utils.index]))
			make_str(&utils, before, env, &output);
	}
	return (output);
}

char	*convert_dollar_sign(t_box *box)
{
	t_list	*node;
	char	*convert;

	node = box->input_split->next;
	while (node)
	{
		if (node->type == dollar)
		{
			convert = convert_dollar(node->content, box->env);
			free(node->content);
			node->content = convert;
			node->type = word;
		}
		node = node->next;
	}
	return (NULL);
}
