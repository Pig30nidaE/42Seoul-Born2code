/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:02:01 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/11 22:07:46 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*addr;

	i = 0;
	addr = dst;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		addr[i] = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}
