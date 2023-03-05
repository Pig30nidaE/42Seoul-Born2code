/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:45:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/19 17:16:51 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_list **arr_a, t_list **arr_b)
{
	int			i;
	int			b_size;

	i = -1;
	b_size = ft_lstsize(*arr_b);
	while ((++i) < b_size)
		ins_crpstn(arr_a, arr_b);
}

t_dir_info	*determining_dir(t_list **arr_a, int target)
{
	int			ra_count;
	int			rra_count;
	t_dir_info	*info;

	ra_count = 0;
	rra_count = 1;
	info = (t_dir_info *)malloc(sizeof(t_dir_info));
	get_rotate_count(arr_a, target, &ra_count, &rra_count);
	if (ra_count < rra_count)
	{
		info->dir = DIR_RA;
		info->op_count = ra_count;
	}
	else
	{
		info->dir = DIR_RRA;
		info->op_count = rra_count;
	}
	return (info);
}

void	get_rotate_count(t_list **arr_a, int target, int *ra, int *rra)
{
	t_list	*first;
	t_list	*a_last;

	first = ft_lstfirst(*arr_a);
	a_last = ft_lstlast(*arr_a);
	while (a_last->content != target)
	{
		(*ra)++;
		a_last = a_last->prev;
	}
	while (first->content != target)
	{
		(*rra)++;
		first = first->next;
	}
}

void	ins_crpstn(t_list **arr_a, t_list **arr_b)
{
	int			i;
	int			b_size;
	int			index;
	t_list		*b_last;
	t_dir_info	*info;

	i = -1;
	b_size = ft_lstsize(*arr_b);
	b_last = ft_lstlast(*arr_b);
	index = 0;
	while ((++i) < b_size && b_last)
	{
		info = determining_dir(arr_a, get_target(arr_a, b_last->content));
		b_last->rota_count = info->op_count;
		b_last->dir = info->dir;
		if (i < b_size / 2)
			b_last->rotb_count = index;
		else
			b_last->rotb_count = b_size - index;
		b_last->cost = b_last->rotb_count + b_last->rota_count;
		b_last = b_last->prev;
		index++;
		free(info);
	}
	run_by_calrst(arr_a, arr_b);
}
