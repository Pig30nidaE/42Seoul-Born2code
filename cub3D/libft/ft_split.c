/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 03:02:02 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/30 03:59:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *str, char c)
{
	int	str_index;
	int	count;

	str_index = 0;
	count = 0;
	while (str[str_index] && str[str_index] == c)
		str_index++;
	while (str[str_index] && str[str_index] != c)
	{
		str_index++;
		count++;
	}
	return (count);
}

static int	get_word_count(char const *str, char c)
{
	int	str_index;
	int	word_count;

	str_index = 0;
	word_count = 0;
	while (str[str_index])
	{
		while (str[str_index] && str[str_index] == c)
			str_index++;
		if (str[str_index])
			word_count++;
		while (str[str_index] && str[str_index] != c)
			str_index++;
	}
	return (word_count);
}

static char	*arr_input(char const *str, char c, int word_len)
{
	int		arr_index;
	int		str_index;
	char	*arr;

	arr_index = 0;
	str_index = 0;
	arr = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!arr)
		return (0);
	arr[word_len] = 0;
	while (str[str_index] && str[str_index] == c)
		(str_index)++;
	while (str[str_index] && str[str_index] != c)
	{
		arr[arr_index] = str[str_index];
		arr_index++;
		str_index++;
	}
	return (arr);
}

char	**free_split(char **arr, int word_count)
{
	int	i;

	i = -1;
	while (++i < word_count)
	{
		if (!arr[i])
		{
			i = -1;
			while (++i < word_count)
				free(arr[i]);
			free(arr);
			return (0);
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;
	int		word_len;
	int		i;
	int		str_index;

	word_count = get_word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (0);
	i = -1;
	str_index = 0;
	while (++i < word_count)
	{
		word_len = get_word_len(&s[str_index], c);
		arr[i] = arr_input(&s[str_index], c, word_len);
		while (s[str_index] == c)
			str_index++;
		str_index += word_len + 1;
	}
	arr[i] = 0;
	arr = free_split(arr, word_count);
	return (arr);
}
