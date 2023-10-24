/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:43:12 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/16 18:09:18 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	to_substr_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	to_substr_len = 0;
	if (s_len < start)
		to_substr_len = 0;
	else if (start + len > s_len)
		to_substr_len = s_len - start;
	else
		to_substr_len = len;
	str = (char *)malloc(sizeof(char) * (to_substr_len + 1));
	if (!str)
		return (0);
	while (i < to_substr_len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
