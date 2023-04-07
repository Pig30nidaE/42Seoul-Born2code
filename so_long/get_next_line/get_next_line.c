/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:28:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/03/13 18:15:43 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*new;
	char			*to_return;
	static char		*arr[OPEN_MAX];
	int				bytes;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	new = read_line(fd, &arr[fd], &bytes);
	to_return = get_to_return(new, &arr[fd], bytes, &i);
	if (!to_return)
	{
		free(new);
		return (0);
	}
	if (arr[fd])
	{
		new = arr[fd];
		arr[fd] = ft_strdup(arr[fd] + i);
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
				return (free_all(arr));
			if (!ft_strchr(*arr, '\n'))
			{
				to_return = get_line_feed(*arr, i);
				free_all(arr);
				return (to_return);
			}
			to_return = get_line_feed(*arr, i);
		}
		else
			return (free_all(arr));
	}
	else
		to_return = get_line_feed(new, i);
	return (to_return);
}

char	*read_line(int fd, char **arr, int *bytes)
{
	char	buf[BUFFER_SIZE + 1];

	*bytes = read(fd, buf, BUFFER_SIZE);
	if (*bytes <= 0)
		return (0);
	while (*bytes)
	{
		buf[*bytes] = '\0';
		if (!(*arr))
			*arr = ft_strdup("");
		*arr = ft_strjoin(*arr, buf);
		if (!arr)
			return (0);
		if (ft_strchr(*arr, '\n'))
			return (*arr);
		*bytes = read(fd, buf, BUFFER_SIZE);
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

char	*free_all(char **arr)
{
	if (*arr)
		free(*arr);
	*arr = 0;
	return (0);
}
