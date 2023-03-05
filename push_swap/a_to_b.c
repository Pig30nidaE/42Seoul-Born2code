/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:50:53 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/19 21:29:23 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_list **arr_a, t_list **arr_b, int s_pivot, int b_pivot)
{
	int	size;
	int	i;

	size = ft_lstsize(*arr_a);
	i = -1;
	while ((++i) < size && ft_lstsize(*arr_a) > 3)
	{
		if (ft_lstlast(*arr_a)->content > b_pivot)
			ra(*arr_a, 1);
		else if (ft_lstlast(*arr_a)->content < s_pivot)
		{
			pb(arr_a, arr_b, 1);
			rb(*arr_b, 1);
		}
		else
			pb(arr_a, arr_b, 1);
	}
	while (ft_lstsize(*arr_a) > 3)
		pb(arr_a, arr_b, 1);
	three_nums(arr_a);
}
