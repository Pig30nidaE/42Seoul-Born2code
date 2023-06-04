/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:25:11 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:40:01 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstadd_back(t_list **node, void *new)
{
	t_list	*head;

	head = *node;
	if (!head)
		*node = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
		head->next->prev = head;
	}
}

t_list	*lstnew(char *content, enum e_type i)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->type = i;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	lstclear(t_list **lst)
{
	t_list	*cur;

	while (*lst)
	{
		cur = (*lst)->next;
		free(*lst);
		*lst = cur;
	}
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lstfirst(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
