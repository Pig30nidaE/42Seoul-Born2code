/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:03:46 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:49:31 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INFILE 0
# define OUTFILE 1
# define PIPE_STDOUT 0
# define PIPE_STDIN 1
# define LIMITER 2

# define NO_PERMIT 2

typedef struct s_env
{
	char		**path;
	char		**env;
}				t_env;

typedef struct s_cmd_arg
{
	char		**arg_arr;
}				t_cmd_arg;

typedef struct s_cmd
{
	char		**cmd;
	t_cmd_arg	*c_arg;
}				t_cmd;

typedef struct s_file
{
	int			fd[2];
}				t_file;

typedef struct s_arg
{
	int			dog_flag;
	int			m_size;
	t_file		file;
	t_cmd		cmd;
	t_env		tenv;
	pid_t		pid;
	int			pipe_fd[2];
}				t_arg;

void			check_fd(int fd);
void			check_argc(int argc);
void			check_cmd(t_arg arg);
void			check_env(char **env);
char			*check_cmd_path_exist(char *str);

void			print_fd_error(void);
void			print_argc_error(void);
void			print_cmd_error(int errno);
void			print_env_error(void);
void			print_pipe_error(void);
void			print_fork_error(void);

char			**get_path_env(char **env);
void			get_cmd_arg(t_arg *arg, char **argv);
int				check_here_doc(t_arg *arg, char *argv1);
void			get_cmd_by_gnl(int fd, char *limiter);
int				get_malloc_size(char **argv);

void			let_fork(t_arg *arg);
char			*find_cmd_path(t_arg *arg, char *cmd);
void			wait_process(void);

void			parents_process(t_arg *arg);
void			infile_to_pipe(t_arg *arg, int count);
void			pipe_to_pipe(t_arg *arg);
void			pipe_to_outfile(t_arg *arg);

void			free_pipex(t_arg *arg, int size);

#endif