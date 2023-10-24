/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:54:23 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/30 02:31:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*to_free(t_list *first, void *mem, void (*del)(void *))
{
	del(mem);
	if (first)
		ft_lstclear(&first, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first;
	void	*ptr;

	if (!lst || !del || !f)
		return (0);
	ptr = f(lst->content);
	new_lst = ft_lstnew(ptr);
	if (!new_lst)
		return (to_free(new_lst, ptr, del));
	first = new_lst;
	lst = lst->next;
	while (lst)
	{
		ptr = f(lst->content);
		new_lst->next = ft_lstnew(ptr);
		if (!(new_lst->next))
			return (to_free(first, ptr, del));
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (first);
}
