/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:40:02 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/16 16:40:57 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1_len;
	int		i;
	char	*return_arr;

	s1_len = ft_strlen(s1);
	i = -1;
	return_arr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!return_arr)
		return (0);
	while (s1[++i])
		return_arr[i] = s1[i];
	return_arr[i] = '\0';
	return (return_arr);
}
