/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:15:02 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/16 19:42:06 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*return_str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!return_str)
		return (0);
	i = -1;
	while ((size_t)(++i) < s1_len)
	{
		*return_str = s1[i];
		return_str++;
	}
	i = -1;
	while ((size_t)(++i) < s2_len)
	{
		*return_str = s2[i];
		return_str++;
	}
	*return_str = '\0';
	return (return_str - (s1_len + s2_len));
}
