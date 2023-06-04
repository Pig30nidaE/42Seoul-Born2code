/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:42 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	input_to_lst(t_list **node, char *str, int start, int end)
{
	char	*tmp;

	tmp = ft_strndup(str, start, end);
	if (!tmp)
		return (1);
	lstadd_back(node, lstnew(tmp, 0));
	return (0);
}

int	is_print_check_space(int c)
{
	if (32 < c && c <= 126)
		return (1);
	return (0);
}

int	write_mode(t_list **node, char *str, int *i, int *start)
{
	if (str[*i] == '<' || str[*i] == '>')
	{
		if (check_redirect(str, *node, i))
			return (-1);
	}
	if (is_print_check_space(str[*i]))
	{
		return (0);
		*start = *i;
	}
	return (1);
}

int	check_quotes(char c, int *flag)
{
	int	i;

	i = (int)c;
	if (c == 34 || c == 39)
	{	
		if (*flag == c)
		{
			*flag = 0;
			return (0);
		}
		else if (*flag == 1 || *flag == 0)
		{
			*flag = c;
			return (c);
		}
		return (1);
	}
	else
		return (1);
}
