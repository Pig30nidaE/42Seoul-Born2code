/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_syntax_alaysis_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:36:21 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:36:21 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

enum e_type	check_syntax_pipe(char *str)
{
	if (ft_strchr(str, '|'))
		return (pipex);
	else
		return (0);
}

enum e_type	check_syntax_redirect(char *str)
{
	if (!ft_strncmp("<\0", str, 2))
		return (infile);
	else if (!ft_strncmp("<<\0", str, 3))
		return (here_doc);
	else if (!ft_strncmp(">\0", str, 2))
		return (outfile);
	else if (!ft_strncmp(">>\0", str, 3))
		return (append);
	else
		return (0);
}

enum e_type	check_syntax_quote(char *str)
{
	if (ft_strchr(str, '\''))
		return (quote);
	if (ft_strchr(str, '\"'))
		return (dquote);
	return (0);
}

enum e_type	check_dollar(char *str)
{
	if (ft_strchr(str, '$'))
		return (dollar);
	else
		return (0);
}

int	count_pipe(t_box *box)
{
	int		cnt;
	int		flag;
	t_list	*node;

	flag = 0;
	cnt = 1;
	node = box->input_split->next;
	while (node != NULL)
	{
		if (node->type == pipex)
		{
			if (flag == 0)
				return (print_syntax_error_int("|"));
			cnt += 1;
			flag = 0;
		}
		if (node->type == word)
			flag = 1;
		node = node->next;
	}
	if ((cnt > 1) && (flag == 0))
		return (print_syntax_error_int("|"));
	return (cnt);
}
