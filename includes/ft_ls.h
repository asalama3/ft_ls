/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/07/01 17:48:41 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <errno.h>

#include <stdio.h>

#define MINORBITS        20
#define MINORMASK        ((1U << MINORBITS) - 1)

#define MAJOR(dev)        ((unsigned int) ((dev) >> MINORBITS))
#define MINOR(dev)        ((unsigned int) ((dev) & MINORMASK))

typedef struct stat		t_stat;

typedef struct timespec		t_timespec;

typedef struct dirent	t_dirent;

typedef struct group	t_group;

typedef struct passwd	t_passwd;

typedef struct		s_flags
{
	int				cap_r;
	int				r;
	int				a;
	int				t;
	int				l;
}					t_flags;

typedef struct		s_arg
{
	t_dirent		*ptr;
	t_stat			*buf;
	t_group			*group;
	DIR				*dir;
	char			*path;
	char			*name;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_file
{
	char			*rights;
	char			*gr_name;
	char			*pw_name;
	char			*buf;
	int				nb_hlink;
	char			*file_name;
	int				size;
	unsigned int	maj;
	unsigned int	min;
	int				nb_blocks;
	char			*time_date;
}					t_file;

/* -------------ERROR ---------------- */
void				ft_error(char option);
t_arg				*error_list(t_arg **old_lst);
void				ft_stat_error(char *file);
void				error_exit(char *str, int error);

/* -------------FLAGS ---------------- */
int					flags(char **argv, t_flags *option);
void				check_flags(t_flags option);

/* -----------LIST_TOOlS -------------- */
int					list_len(t_arg **lst);
void				position_front(t_arg *runner, t_arg *tmp);
void				position_back(t_arg *runner, t_arg *tmp);
void				position_insert(t_arg *tmp);
void				push_back(t_arg *runner, t_arg **begin_lst);
void				init_lst(t_arg *runner);
void				print_arg_list(t_arg *lst, t_flags *option, t_file *file);
void				print_file(t_arg *runne, t_flags *optionr);
char				*get_path(char *dir, char *name);

/* ---------------LS ------------------- */
int					ft_ls(char **argv, t_flags option);
char				*get_path(char *dir, char *name);
int					check_stat(t_arg *link, char *file, t_flags *option);
t_arg				*link_malloc();
void				create_link_arg(t_arg *link, t_arg **arg_lst);
void				rec(t_arg *dir_lst, t_flags *option, t_file *file);
int					make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option, t_file *file);

/* -------------LIST_SORT --------------- */
void				sort_flags(t_flags *option, t_arg **arg_lst);
void				arg_sort_alpha(t_arg **arg_lst);
void				arg_sort_file_dir(t_arg **old_lst);

/* -------------TEST_DIR_FILE --------------- */
void				test_dir(t_arg **old_lst, t_flags *option, t_arg *error_lst);
void				test_file(t_arg **old_lst);

/* -------------L_OPTION --------------- */
void				get_rights(t_arg *runner, t_file *file);
void				nb_hardlinks(t_arg *runner, t_file *file);
void				get_file_owner(t_arg *runner, t_file *file);
void				get_file_group(t_arg *runner, t_file *file);
void				get_sticky_bits(t_file *file);
void				get_file_size(t_arg *runner, t_file *file);
void				get_file_time(t_arg *runner, t_file *file);
void				get_file_name(t_arg *runner, t_file *file);
void				get_link(t_arg *runner, t_file *file);
void				total(t_arg *runner, t_file *file);
void				print_l_info(t_file *file);
void				print_total(t_file *file);
void				l_info(t_arg *runner, t_file *file);

/* -------------ACL --------------- */
void				get_acl(char *filename);


#endif
