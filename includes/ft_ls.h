/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/06/22 19:15:43 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <errno.h>

#include <stdio.h>

typedef struct stat		t_stat;

typedef struct dirent	t_dirent;

typedef struct group	t_group;

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
	char			*gid;
	char			*pwd;
	int				nb_link;
	char			*file_name;
	int				size;
	int				time_date;
}					t_file;

/* -------------ERROR ---------------- */
void				ft_error(char option);
void				error_list(t_arg **old_lst);
void				ft_stat_error(char *file);

/* -----------LIST_TOOlS -------------- */
int					list_len(t_arg **lst);
void				position_front(t_arg *runner, t_arg *tmp);
void				position_back(t_arg *runner, t_arg *tmp);
void				position_insert(t_arg *tmp);
void				push_back(t_arg *runner, t_arg **begin_lst);
void				init_lst(t_arg *runner);
void				print_arg_list(t_arg *lst);
void				print_file(t_arg *runner);
/* ---------------LS ------------------- */
int					ft_ls(char **argv, t_flags option);
int					check_stat(t_arg *link, char *file);
t_arg				*link_malloc();
void				create_link_arg(t_arg *link, t_arg **arg_lst);
//void				make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option);
void				rec(t_arg *dir_lst, t_flags *option);

/* -------------LIST_SORT --------------- */
void				sort_flags(t_flags *option, t_arg **arg_lst);
void				arg_sort_alpha(t_arg **arg_lst);
void				arg_sort_file_dir(t_arg **old_lst);

void				test_dir(t_arg **old_lst, t_flags *option);

/* -------------L_OPTION --------------- */
char				*get_rights(t_arg *runner);
int					nb_hardlinks(t_arg *runner);
void				get_file_group(t_arg *runner);
void				print_rights(char *rights, int len);

#endif
