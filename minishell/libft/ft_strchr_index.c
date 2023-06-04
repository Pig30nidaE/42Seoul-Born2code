/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:24:53 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:24:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_index(const char *s, int c)
{
	int	i;

	i = -1;
	c = (char)c;
	if (c == 0)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (0);
}
