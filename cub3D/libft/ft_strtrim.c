/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:44:16 by sanghyol          #+#    #+#             */
/*   Updated: 2023/07/17 20:42:48 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_end_addr(char const *s1, char const *set)
{
	size_t		len;

	if (!(*s1))
		return (0);
	len = ft_strlen(s1);
	if (len)
		len--;
	else
		return (0);
	while (*(s1 + len))
	{
		if (!ft_strchr(set, *(s1 + len)))
			break ;
		else
			len--;
	}
	return (len + 1);
}

static int	get_start_addr(char const *s1, char const *set)
{
	size_t		i;

	i = 0;
	if (!(*s1))
		return (0);
	while (*s1)
	{
		if (ft_strchr(set, *s1) == 0)
			break ;
		else
			i++;
		s1++;
	}
	return (i);
}

static char	*return_none_str(char *s1)
{
	char	*return_str;

	free(s1);
	return_str = ft_strdup("");
	return (return_str);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		start;
	int		end;
	char	*return_str;
	int		i;

	start = get_start_addr(s1, set);
	end = get_end_addr(s1, set);
	if (start > end)
		return (return_none_str(s1));
	return_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!return_str)
	{
		free(s1);
		return (0);
	}
	i = -1;
	while (start < end)
	{
		return_str[++i] = s1[start];
		start++;
	}
	return_str[i + 1] = '\0';
	free(s1);
	return (return_str);
}
