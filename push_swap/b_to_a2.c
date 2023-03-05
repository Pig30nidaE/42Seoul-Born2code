/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:45:35 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/19 17:09:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_to_pa(t_list **arr_a, t_list **arr_b)
{
	int		min_cost;
	t_list	*to_pa;
	t_list	*b_last;

	min_cost = ft_lstsize(*arr_a) + ft_lstsize(*arr_b);
	b_last = ft_lstlast(*arr_b);
	while (b_last)
	{
		if (b_last->cost < min_cost)
		{
			to_pa = b_last;
			min_cost = b_last->cost;
		}
		b_last = b_last->prev;
	}
	return (to_pa);
}

void	b_to_a_size_under_half(t_list **arr_a, t_list **arr_b, t_list *to_pa)
{
	int	i;

	i = -1;
	if (to_pa->dir == DIR_RA)
	{
		while ((++i) != to_pa->rota_count)
		{
			if (ft_lstlast(*arr_b) != to_pa)
				rr(*arr_a, *arr_b);
			else
				ra(*arr_a, 1);
		}
	}
	else
	{
		while ((++i) != to_pa->rota_count)
			rra(*arr_a, 1);
	}
	while (ft_lstlast(*arr_b) != to_pa)
		rb(*arr_b, 1);
}

void	b_to_a_size_over_half(t_list **arr_a, t_list **arr_b, t_list *to_pa)
{
	int	i;

	i = -1;
	if (to_pa->dir == DIR_RA)
	{
		while ((++i) != to_pa->rota_count)
			ra(*arr_a, 1);
	}
	else
	{
		while ((++i) != to_pa->rota_count)
		{
			if (ft_lstlast(*arr_b) != to_pa)
				rrr(*arr_a, *arr_b);
			else
				rra(*arr_a, 1);
		}
	}
	while (ft_lstlast(*arr_b) != to_pa)
		rrb(*arr_b, 1);
}

void	run_by_calrst(t_list **arr_a, t_list **arr_b)
{
	t_list		*b_last;
	t_list		*to_pa;
	int			count;

	to_pa = get_to_pa(arr_a, arr_b);
	count = 0;
	b_last = ft_lstlast(*arr_b);
	while (b_last != to_pa)
	{
		count++;
		b_last = b_last->prev;
	}
	if (count <= (ft_lstsize(*arr_b) / 2))
		b_to_a_size_under_half(arr_a, arr_b, to_pa);
	else
		b_to_a_size_over_half(arr_a, arr_b, to_pa);
	pa(arr_a, arr_b, 1);
}

int	get_target(t_list **arr_a, int num)
{
	int		i;
	int		a_size;
	t_list	*first;
	int		target;

	i = -1;
	a_size = ft_lstsize(*arr_a);
	first = ft_lstfirst(*arr_a);
	target = get_max(first);
	if (target < num || get_min(ft_lstlast(*arr_a), target) > num)
		return (get_min(ft_lstlast(*arr_a), target));
	while ((++i) < a_size)
	{
		if (first->content - num > 0 && first->content < target)
			target = first->content;
		first = first->next;
	}
	return (target);
}
