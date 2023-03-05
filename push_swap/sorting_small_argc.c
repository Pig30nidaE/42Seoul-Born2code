/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_argc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:47:26 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/23 17:41:39 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argc_check(int arr_size, t_list **arr_a)
{
	if (arr_size == 0)
		return (0);
	else if (arr_size == 1)
		return (1);
	else if (arr_size == 2)
		two_nums(arr_a);
	else if (arr_size == 3)
		three_nums(arr_a);
	else
		return (0);
	return (1);
}

void	two_nums(t_list **arr_a)
{
	if (ft_lstlast(*arr_a) < ft_lstfirst(*arr_a))
		sa(*arr_a, 1);
}

void	three_nums(t_list **arr_a)
{
	int	last;
	int	middle;
	int	first;

	last = ft_lstlast(*arr_a)->content;
	middle = ft_lstfirst(*arr_a)->next->content;
	first = ft_lstfirst(*arr_a)->content;
	if (first > middle && middle > last)
		return ;
	else if (first > last && last > middle)
		sa(*arr_a, 1);
	else if (middle > first && first > last)
		rra_sa(arr_a);
	else if (middle > last && last > first)
		rra(*arr_a, 1);
	else if (last > first && first > middle)
		ra(*arr_a, 1);
	else
		ra_sa(arr_a);
}
