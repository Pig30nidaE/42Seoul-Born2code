/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:52:07 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

enum				e_type
{
	dquote = 1,
	quote,
	dollar,
	word,
	redirect_arg,
	here_doc,
	infile,
	outfile,
	append,
	pipex,
	null,
};

typedef struct s_list
{
	char			*content;
	enum e_type		type;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char				**free_all(char **arr, int word_count);
char				**ft_split(char const *s, char c);

char				*ft_strjoin_libft(char const *s1, char const *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_ascii_cmp(char *s1, char *s2);

size_t				ft_strlen(const char *s);

void				ft_putendl_fd(char *s, int fd);

void				ft_putstr_fd(char *s, int fd);

char				*ft_strchr(const char *s, int c);

char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);

int					ft_isprint(int c);

int					ft_isalpha(int c);
int					ft_isstring(char *str);

char				*ft_strdup(const char *s1);

char				*ft_strndup(const char *s1, int start, int end);

int					ft_strchr_index(const char *s, int c);

void				lstadd_back(t_list **node, void *new);
t_list				*lstnew(char *content, enum e_type i);
void				lstclear(t_list **lst);
t_list				*lstlast(t_list *lst);
t_list				*lstfirst(t_list *lst);

#endif