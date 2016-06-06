/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/06/06 20:41:21 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <errno.h>
#include <sys/stat.h>

#include <stdio.h>

typedef struct stat		t_stat;

typedef struct dirent	t_dirent;

typedef struct		s_flags
{
	int				cap_r;
	int				r;
	int				a;
	int				t;
	int				l;
}					t_flags;

/*typedef struct		s_lst
{
//	t_flags         *flags;
	t_init			*init;
    char			*file;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;
*/

/*typedef struct		s_err
{
	char			*file;
	int				error;
	struct s_err	*next;
	struct s_err	*prev;
}					t_err;
*/
typedef struct		s_arg
{
//	t_dirent		*sd;
	t_stat			*buf;
	DIR				*dir;
	char			*path;
	char			*name;
	struct s_arg	*next;
	struct s_arg	*prev;
	struct s_arg	*new_list;
}					t_arg;


/* -------------ERROR ---------------- */
void				ft_error(char option);
void				error_list(t_arg **old_lst);

/* -----------LIST_TOOlS -------------- */
int					list_len(t_arg **lst);
void				position_front(t_arg *runner, t_arg *tmp);
void				position_back(t_arg *runner, t_arg *tmp);
void				position_insert(t_arg *tmp);
void				push_back(t_arg *runner, t_arg **begin_lst);
void				init_lst(t_arg *runner);
void				print_arg_list(t_arg *lst);

/* ---------------LS ------------------- */
int					ft_ls(char **argv, t_flags option);
void				create_link_arg(t_arg *link, t_arg **arg_lst);

/* -------------LIST_SORT --------------- */
void				sort_flags(t_flags *option, t_arg **arg_lst);
void				arg_sort_alpha(t_arg **arg_lst);
void				arg_sort_file_dir(t_arg **old_lst);
#endif
