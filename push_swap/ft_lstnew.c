/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:09:43 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/15 21:31:53 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*arr;

	arr = (t_list *)malloc(sizeof(t_list));
	if (!arr)
		return (0);
	arr->prev = 0;
	arr->next = 0;
	arr->content = content;
	return (arr);
}
