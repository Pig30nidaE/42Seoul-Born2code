/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:12:09 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 15:25:34 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define SMALL_PIVOT 1
# define BIG_PIVOT 2
# define DIR_RA 1
# define DIR_RRA 2
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				content;
	int				cost;
	int				rota_count;
	int				rotb_count;
	int				dir;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_dir_info
{
	int				dir;
	int				op_count;
}					t_dir_info;

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

void				num_check(char *str, char **str_start);
int					is_num(char *str);
void				error_exit(void);
void				arr_init(int argc, char **argv, t_list **arr_a,
						t_list **arr_b);
void				arr_linking(t_list **arr_a, int index);
void				pre_sort(int **return_arr, int size, t_list *input_arr);
int					get_max(t_list *first);
int					get_min(t_list *last, int max);

void				pa(t_list **arr_a, t_list **arr_b, int print_flag);
void				pb(t_list **arr_a, t_list **arr_b, int print_flag);
void				check_prev_exist(t_list *last);
void				ra(t_list *arr_a, int print_flag);
void				rb(t_list *arr_b, int print_flag);
void				rr(t_list *arr_a, t_list *arr_b);
void				sa(t_list *arr_a, int print_flag);
void				sb(t_list *arr_b, int print_flag);
void				ss(t_list *arr_a, t_list *arr_b);
void				rra(t_list *arr_a, int print_flag);
void				rrb(t_list *arr_b, int print_flag);
void				rrr(t_list *arr_a, t_list *arr_b);
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

int					argc_check(int arr_size, t_list **arr_a);
void				two_nums(t_list **arr_a);
void				three_nums(t_list **arr_a);
void				a_to_b(t_list **arr_a, t_list **arr_b, int s_pivot,
						int b_pivot);
void				get_rotate_count(t_list **arr_a, int target, int *ra,
						int *rra);
t_dir_info			*determining_dir(t_list **arr_a, int target);
void				run_by_calrst(t_list **arr_a, t_list **arr_b);
int					get_target(t_list **arr_a, int num);
void				b_to_a(t_list **arr_a, t_list **arr_b);
t_dir_info			*determining_dir(t_list **arr_a, int target);
void				get_rotate_count(t_list **arr_a, int target, int *ra,
						int *rra);
void				ins_crpstn(t_list **arr_a, t_list **arr_b);
t_list				*get_to_pa(t_list **arr_a, t_list **arr_b);
void				b_to_a_size_under_half(t_list **arr_a, t_list **arr_b,
						t_list *to_pa);
void				b_to_a_size_over_half(t_list **arr_a, t_list **arr_b,
						t_list *to_pa);
void				surplus_sorting(t_list **arr_a);
void				surplus_rot(int count, t_list **arr_a);

#endif