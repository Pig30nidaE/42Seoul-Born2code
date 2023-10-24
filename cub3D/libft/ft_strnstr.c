/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:24:03 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/15 21:02:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (i < len && *(haystack + i))
	{
		j = 0;
		if (*(haystack + i) == *needle)
		{
			while (j + i < len && *(needle + j) && *(haystack + i + j))
			{
				if (*(needle + j) != *(haystack + i + j))
					break ;
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
