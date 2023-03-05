/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:03:06 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 18:01:34 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free((void *)s1);
	return (return_str - (s1_len + s2_len));
}

char	*ft_strdup(const char *s1)
{
	int		s1_len;
	int		i;
	char	*return_arr;

	s1_len = ft_strlen(s1);
	i = -1;
	return_arr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!return_arr)
	{
		free((void *)s1);
		return (0);
	}
	while (s1[++i])
		return_arr[i] = s1[i];
	return_arr[i] = '\0';
	return (return_arr);
}

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

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
		return (free_func((char **)&s));
	while (i < to_substr_len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
