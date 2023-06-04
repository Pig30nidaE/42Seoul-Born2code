/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:48 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:18:50 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int start, int end)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = end - start + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = *((char *)s1 + start + i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
