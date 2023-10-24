/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:27:07 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/11 22:08:04 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*addr;

	j = 0;
	addr = dst;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		i = len - 1;
		while (j < len)
		{
			addr[i] = *((unsigned char *)(src + i));
			i--;
			j++;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
