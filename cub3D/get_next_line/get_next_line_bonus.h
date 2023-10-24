/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:43:15 by sanghyol          #+#    #+#             */
/*   Updated: 2022/12/13 20:45:24 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);
char	*read_line(int fd, char **arr, int *bytes);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*get_line_feed(char *src, size_t *i);
char	*free_all(char **arr);
char	*get_to_return(char *new, char **arr, int bytes, size_t *i);

#endif