/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:41 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/22 17:42:36 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*addr;

	if (size * count > SIZE_MAX)
		return (0);
	addr = malloc(size * count);
	if (!(addr))
		return (0);
	ft_bzero(addr, count * size);
	return (addr);
}
