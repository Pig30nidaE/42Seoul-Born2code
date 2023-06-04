/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:34:56 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:34:57 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_charjoin(const char *s1, const char c)
{
	size_t	len;
	char	*output;
	size_t	i;

	len = ft_strlen(s1) + 1;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = c;
	output[len] = '\0';
	return (output);
}

char	*cut_quote(char *str)
{
	t_token_utils	utils;
	char			*tmp;
	char			*output;

	output = ft_strdup("");
	utils.flag = 1;
	utils.index = -1;
	while (str[++utils.index])
	{
		if (!check_quotes(str[utils.index], &utils.flag))
			continue ;
		if (ft_isprint(str[utils.index]) && (utils.flag != str[utils.index]))
		{
			tmp = ft_charjoin(output, str[utils.index]);
			free(output);
			output = tmp;
			tmp = NULL;
		}
	}
	free(str);
	return (output);
}
