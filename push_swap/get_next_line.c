/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:28:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 19:40:30 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, size_t buffer_size)
{
	char			*new;
	char			*to_return;
	static char		*arr;
	int				bytes;
	size_t			i;

	if (fd < 0 || buffer_size <= 0)
		return (0);
	i = 0;
	new = read_line(fd, &arr, &bytes, buffer_size);
	to_return = get_to_return(new, &arr, bytes, &i);
	if (!to_return)
	{
		free(new);
		return (0);
	}
	if (arr)
	{
		new = arr;
		arr = ft_strdup(arr + i);
		free(new);
	}
	return (to_return);
}

char	*get_to_return(char *new, char **arr, int bytes, size_t *i)
{
	char	*to_return;

	if (!new)
	{
		if (*arr)
		{
			if (bytes < 0)
				return (free_func(arr));
			if (!ft_strchr(*arr, '\n'))
			{
				to_return = get_line_feed(*arr, i);
				free_func(arr);
				return (to_return);
			}
			to_return = get_line_feed(*arr, i);
		}
		else
			return (free_func(arr));
	}
	else
		to_return = get_line_feed(new, i);
	return (to_return);
}

char	*read_line(int fd, char **arr, int *bytes, size_t buffer_size)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (buffer_size + 1));
	*bytes = read(fd, buf, buffer_size);
	if (*bytes <= 0)
		return (free_func(&buf));
	while (*bytes)
	{
		buf[*bytes] = '\0';
		if (!(*arr))
			*arr = ft_strdup("");
		*arr = ft_strjoin(*arr, buf);
		if (!arr)
			return (0);
		if (ft_strchr(*arr, '\n'))
		{
			free(buf);
			return (*arr);
		}
		*bytes = read(fd, buf, buffer_size);
	}
	if (*arr)
		return (*arr);
	return (0);
}

char	*get_line_feed(char	*src, size_t *i)
{
	char	*temp;

	if (!src)
		return (0);
	if (ft_strlen(src) <= 0)
		return (0);
	*i = 0;
	while (src[*i] && src[*i] != '\n')
		(*i)++;
	if (src[*i] == '\n')
		(*i)++;
	temp = ft_substr(src, 0, *i);
	if (!temp)
		return (0);
	return (temp);
}

char	*free_func(char **arr)
{
	if (*arr)
		free(*arr);
	*arr = 0;
	return (0);
}
