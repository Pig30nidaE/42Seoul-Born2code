/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:38:36 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/11 20:02:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*s_copy;

	i = 0;
	chr = (unsigned char)c;
	s_copy = (unsigned char *)s;
	while (i < n)
	{
		if (s_copy[i] == chr)
			return (s_copy + i);
		i++;
	}
	return (0);
}
