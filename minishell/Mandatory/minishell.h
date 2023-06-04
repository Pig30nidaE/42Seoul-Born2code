/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:26:52 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:46:43 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>

# define INFILE 0
# define OUTFILE 1
# define PIPE_STDOUT 0
# define PIPE_STDIN 1

# define GENERAL_ERROR 1
# define NO_PERMIT 126
# define PATH_ERROR 127

int					g_error_code;

typedef struct s_token_utils
{
	int				index;
	int				flag;
	int				start;
}					t_token_utils;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
	int				order;
	int				built_last_env_flag;
}					t_env;

typedef struct s_exe
{
	t_list			*redirect;
	char			*cmd;
	char			**args;
	int				infd;
	int				outfd;
	char			*infile;
	char			*outfile;
}					t_exe;

typedef struct s_box
{
	t_list			*input_split;
	t_env			*env;
	t_exe			**exe;
	char			**path;
	char			**env_save;
	int				pipe_size;
	t_list			*here_doc;
	int				pipe_fd[2];
	pid_t			pid;
	int				stdin;
}					t_box;

char				**get_path_env(char **env);

void				pre_process_before_fork(t_box *box, int *i);
void				let_fork(t_box *box);
void				fork_behv_brcin_by_pid(t_box *box, int i);
void				wait_process(pid_t pid);
void				wait_proc_branching_by_status(int status, int *i);
char				*find_cmd_path(t_box *box, char *cmd);

void				redirect_open_files(t_exe *exe);
void				redirect_cloes_files(t_exe *exe);
void				nopipe_to_file_stream(t_box *box, t_exe *exe);
void				with_pipe_to_file_stream(t_box *box, t_exe *exe);
void				get_input_til_limiter(int fd, char *limiter, t_env *env);
void				check_heredoc(t_box *box, t_exe *exe, int i);

void				change_stream(t_box *box, t_exe *exe, int i);
void				parents_process(t_box *box);
void				infile_to_outfile(t_box *box, t_exe *exe);
void				infile_to_pipe(t_box *box, t_exe *exe);
void				pipe_to_pipe(t_box *box);
void				pipe_to_outfile(t_box *box, t_exe *exe);
void				infile_to_stdout(t_box *box, t_exe *exe);
void				pipe_to_stdout(t_box *box);
void				stdin_to_pipe(t_box *box);
void				stdin_to_outfile(t_box *box, t_exe *exe);

void				run_prompt(t_box *box);
void				run_builtin(t_box *box, char *cmd, char **args);
int					check_is_builtin(char *cmd);
void				heredoc_unlink(void);

void				ft_pwd(void);
void				ft_cd(t_env *env, char **args, int pipe_size);
void				ft_env(t_env *env, int pipe_size);
void				ft_unset(t_env *env, char **args);
void				ft_export(t_box *box, char **args);
void				export_add_env(t_env *env, char **args);
void				export_print_env(t_env *env);
void				expt_add_behv_is_eq(t_env *env,
						char **args, int equal_index, int i);
void				expt_add_behv_isnt_eq(t_env *env,
						char **args, int i);
void				expt_prt_added_env(t_env *env);
void				ft_echo(char **str, int pipe_size);
int					is_echo_option_exist(char *option);
void				ft_exit(t_box *box, char **args);
void				exit_behavior_is_args(t_box *box, char **args);

char				*check_cmd_path_exist(char *cmd, char *str, int pipe_size);
void				check_fd(char *file_name, int fd, int pipe_size);

void				print_no_such_fd(char *cmd, char *path,
						int pipe_size, int errno);
void				no_such_fd_branching(char *cmd, char *path,
						int pipe_size, int errno);
void				print_fork_error(void);
void				print_pipe_error(void);
void				print_cmd_error(char *cmd, int errno);
void				print_too_many_args(t_box *box, char *cmd);
void				print_numeric_need(char *cmd, char *args);
void				*print_syntax_error_null(char *err);
int					print_syntax_error_int(char *err);

int					parsing(char *str, t_box *box);

int					make_token(char *str, t_list *HEAD);
char				*ft_strndup(const char *s1, int start, int end);

int					input_to_lst(t_list **node, char *str, int start, int end);
int					is_print_check_space(int c);
int					write_mode(t_list **node, char *str, int *i, int *start);
int					check_quotes(char c, int *flag);
int					check_redirect(char *str, t_list *head, int *i);

char				**get_two_array_env(t_env *env);

char				*ft_charjoin(const char *s1, const char c);
char				*cut_quote(char *str);

int					syntax_alaysis(t_box *box);

char				*convert_dollar_sign(t_box *box);
char				*contact_dollar(char *str, t_env *env,
						t_token_utils *utils);

char				*replace_dollar_value(t_token_utils *utils, char *str,
						t_env *env);

char				*convert_dollar_heredoc(char *input, t_env *env);

int					count_pipe(t_box *box);
enum e_type			check_dollar(char *str);
enum e_type			check_syntax_quote(char *str);
enum e_type			check_syntax_redirect(char *str);
enum e_type			check_syntax_pipe(char *str);

int					redirect_to_exe(t_box *box);

int					cmd_args_to_exe(t_box *box);

t_env				*set_envp(char **envp);
t_env				*envnew(char *key, char *value);
char				*get_key(char *str, int len);
char				*get_value(char *str, int start);

t_env				*envfirst(t_env *env);
t_env				*envlast(t_env *env);
void				env_addback(t_env *env, char *key, char *value);
char				*get_env_by_key(t_env *env, char *key);
void				envdel(t_env *env);
int					is_key_exist(t_env *env, char *key);
void				env_modify_value(t_env *env, char *key, char *value);
int					env_size(t_env *env);

t_box				*init_box(void);

t_exe				**exe_init(int size);

void				set_signal(int set_num);
void				input_signal_handler(int signal);
void				child_signal_handler(int signal);

void				set_term(void);
void				unset_term(void);

void				free_box_partial(t_box **box);
void				free_box_all(t_box **box);

void				free_list(t_list **input);
void				free_env(t_env **input);
void				free_2d_exe(t_exe ***input);
void				free_2d_char(char ***input);

void				print_cmd_args(t_box *box);
void				print_input(t_box *box);
void				print_here_redirect(t_box **box);
void				check_parse(t_box *test);
void				print_env(t_env *env);
void				check_char_env(char **env, char **arg_env);

#endif