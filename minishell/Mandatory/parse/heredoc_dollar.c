/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:44:38 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*make_convert_str(char *input, t_env *env, t_token_utils *utils)
{
	char	*str;
	char	*front;
	char	*back;

	front = ft_substr(input, 0, utils->index);
	str = contact_dollar(input, env, utils);
	back = ft_substr(input, utils->index + 1, \
	ft_strlen(&(input[utils->index])));
	free(input);
	input = ft_strjoin_libft(front, str);
	free(str);
	free(front);
	str = ft_strjoin_libft(input, back);
	free(input);
	input = str;
	str = NULL;
	free(back);
	return (input);
}

char	*convert_dollar_heredoc(char *input, t_env *env)
{
	t_token_utils	utils;

	utils.flag = '\'';
	utils.index = -1;
	while (input[++(utils.index)])
	{
		if (input[utils.index] == '$')
			input = make_convert_str(input, env, &utils);
	}
	return (input);
}
