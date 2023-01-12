/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:03:54 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/09 22:13:36 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*addr;

	c = (char)c;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	addr = s + ft_strlen(s) - 1;
	while (*addr)
	{
		if (*addr == c)
			return ((char *)addr);
		if (addr == s)
			break ;
		addr--;
	}
	return (0);
}
