/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:14:19 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 21:38:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	run_operations(t_list **arr_a, t_list **arr_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0, 5);
		if (!str)
			return ;
		cmp_operations(str, ft_strlen(str), arr_a, arr_b);
		free(str);
	}
}

void	cmp_operations(char *buf, size_t len, t_list **arr_a, t_list **arr_b)
{
	if (!ft_strncmp("ra\n", buf, len))
		ra(*arr_a, 0);
	else if (!ft_strncmp("rb\n", buf, len))
		rb(*arr_b, 0);
	else if (!ft_strncmp("rr\n", buf, len))
		rr_with_no_print(*arr_a, *arr_b);
	else if (!ft_strncmp("pa\n", buf, len))
		pa(arr_a, arr_b, 0);
	else if (!ft_strncmp("pb\n", buf, len))
		pb(arr_a, arr_b, 0);
	else if (!ft_strncmp("rra\n", buf, len))
		rra(*arr_a, 0);
	else if (!ft_strncmp("rrb\n", buf, len))
		rrb(*arr_b, 0);
	else if (!ft_strncmp("rrr\n", buf, len))
		rrr_with_no_print(*arr_a, *arr_b);
	else if (!ft_strncmp("sa\n", buf, len))
		sa(*arr_a, 0);
	else if (!ft_strncmp("sb\n", buf, len))
		sb(*arr_b, 0);
	else if (!ft_strncmp("ss\n", buf, len))
		ss_with_no_print(*arr_a, *arr_b);
	else
		error_exit();
}
