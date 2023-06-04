/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:22:37 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	**free_all(char **arr, int word_count);
char	**ft_split(char const *s, char c);

char	*ft_strjoin_libft(char const *s1, char const *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

void	ft_putendl_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif