/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:12:09 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 19:19:31 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void				check_sorted(t_list **arr_a, t_list **arr_b);
void				run_operations(t_list **arr_a, t_list **arr_b);
void				cmp_operations(char *buf, size_t len, t_list **arr_a,
						t_list **arr_b);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
t_list				*ft_lstnew(int content);
int					get_sign(char str, int *i);
int					ft_atoi(const char *str);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfirst(t_list *lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
void				clear_lst(t_list **arr_a, t_list **arr_b);
int					get_word_len(char const *str, char c);
int					get_word_count(char const *str, char c);
char				*arr_input(char const *str, char c, int word_len);
char				**free_all(char **arr, int word_count);
char				**ft_split(char const *s, char c);
int					get_base_arr_size(char **argv);
int					arr_size(char **arr);
int					is_all_sorted(t_list **arr_a);
int					redundancy_check(int *prp_arr, int arr_size);
int					exception_handling(int arr_size, t_list **arr_a,
						t_list **arr_b);
void				split_check(char **arr);
void				num_check(char *str);
int					is_num(char *str);
void				error_exit(void);
int					argc_check(int arr_size, t_list **arr_a);
void				arr_init(int argc, char **argv, t_list **arr_a,
						t_list **arr_b);
void				pre_sort(int **return_arr, int size, t_list *input_arr);
void				two_nums(t_list **arr_a);
void				three_nums(t_list **arr_a);

void				pa(t_list **arr_a, t_list **arr_b, int print_flag);
void				pb(t_list **arr_a, t_list **arr_b, int print_flag);
void				check_prev_exist(t_list *last);
void				ra(t_list *arr_a, int print_flag);
void				rb(t_list *arr_b, int print_flag);
void				rr(t_list *arr_a, t_list *arr_b);
void				sa(t_list *arr_a, int print_flag);
void				sb(t_list *arr_b, int print_flag);
void				ss(t_list *arr_a, t_list *arr_b);
void				ss_with_no_print(t_list *arr_a, t_list *arr_b);
void				rra(t_list *arr_a, int print_flag);
void				rrb(t_list *arr_b, int print_flag);
void				rrr(t_list *arr_a, t_list *arr_b);
void				rr_with_no_print(t_list *arr_a, t_list *arr_b);
void				rrr_with_no_print(t_list *arr_a, t_list *arr_b);
void				rra_sa(t_list **arr_a);
void				ra_sa(t_list **arr_a);
void				pa_ra(t_list **arr_a, t_list **arr_b);

void				print_pa(int print_flag);
void				print_pb(int print_flag);
void				print_ra(int print_flag);
void				print_rb(int print_flag);
void				print_rr(int print_flag);
void				print_sa(int print_flag);
void				print_sb(int print_flag);
void				print_ss(int print_flag);
void				print_rra(int print_flag);
void				print_rrb(int print_flag);
void				print_rrr(int print_flag);
#endif