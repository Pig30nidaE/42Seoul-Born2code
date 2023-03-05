/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:23:34 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 15:25:01 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_size(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	arr_linking(t_list **arr_a, int index)
{
	if (index > 0)
	{
		arr_a[index]->next = arr_a[index - 1];
		arr_a[index]->next->prev = arr_a[index];
	}
}
