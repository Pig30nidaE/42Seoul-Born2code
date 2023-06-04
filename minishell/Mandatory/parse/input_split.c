/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:46 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:35:46 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_read_mode(t_list *node, char *str, t_token_utils *utils)
{
	char	*tmp;
	int		i;
	int		start;
	int		flag;

	flag = utils->flag;
	start = utils->start;
	i = utils->index;
	if (flag == 0 && (str[i] == '\0' || str[i] == ' ' || str[i] == '<' \
	|| str[i] == '>' || str[i] == '\n' || str[i] == '|'))
	{
		tmp = ft_strndup(str, start, i - 1);
		if (!tmp)
			return (1);
		lstadd_back(&node, lstnew(tmp, 0));
		utils->flag = 1;
	}
	return (0);
}

int	check_redirect(char *str, t_list *head, int *i)
{
	int		start;

	if (str[*i] == '<')
	{
		start = *i;
		if (str[(*i) + 1] == '>')
			return (input_to_lst(&head, str, start, *i));
		else if (str[(*i) + 1] == '<')
			(*i)++;
		return (input_to_lst(&head, str, start, *i));
	}
	else if (str[*i] == '>')
	{
		start = *i;
		if (str[(*i) + 1] == '<')
			return (input_to_lst(&head, str, start, *i));
		else if (str[(*i) + 1] == '>')
			(*i)++;
		return (input_to_lst(&head, str, start, *i));
	}
	return (0);
}

static int	tokenize(t_list *head, char *str, t_token_utils *utils)
{
	if (check_read_mode(head, str, utils))
		return (1);
	if (str[utils->index] == '\0')
		return (0);
	if (utils->flag == 1)
	{
		if (check_redirect(str, head, &utils->index))
			return (1);
		if (str[utils->index] == '<' || str[utils->index] == '>')
			return (0);
		if (str[utils->index] == '|')
			return (input_to_lst(&head, str, utils->index, utils->index));
		if (is_print_check_space(str[utils->index]))
		{
			utils->flag = 0;
			utils->start = utils->index;
		}
	}
	check_quotes(str[utils->index], &utils->flag);
	return (0);
}

int	make_token(char *str, t_list *head)
{
	t_token_utils	utils;

	utils.flag = 1;
	utils.index = -1;
	utils.start = 1;
	while (1)
	{
		utils.index += 1;
		if (tokenize(head, str, &utils))
			exit(1);
		if (str[utils.index] == 0)
			break ;
	}
	if (utils.flag != 1)
		return (print_syntax_error_int("quote"));
	return (1);
}
