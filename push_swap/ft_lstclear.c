/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:41:51 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 12:38:22 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	*lst = ft_lstfirst(*lst);
	if (lst)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp);
		}
	}
}
