/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/05/17 17:23:09 by asalama          ###   ########.fr       */
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

/*
typedef struct		s_init
{
	struct dirent	*ptr;
	DIR				*dir;
	struct stat		*buf;
}					t_init;
*/
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

typedef struct		s_err
{
	char			*file;
	int				error;
	struct s_err	*next;
	struct s_eff	*prev;
}					t_err;

typedef struct		s_arg
{
//	t_init			*init;
//	t_dirent		*sd;
	t_stat			*buf;
	DIR				*dir;
	char			*path;
	char			*name;
	struct s_arg	*next;
	struct s_arg	*prev;
	struct s_arg	*new_list;
}					t_arg;


//int					get_av_list(char **argv, t_flags option, t_arg *arg_lst);
void				ft_error(char option);
int					list_len(t_arg **lst);
void				push_front(t_arg **lst, t_arg *new);
void				push_back(t_arg *runner, t_arg *new);
void				print_av_list(t_arg *lst);
int					ft_ls(char **argv, t_flags option);
void					link_arg(t_arg *link, t_arg **arg_lst);
//int					parse(t_init *in, int argc, char **argv, int k);
//void				ft_dir_error(char *file);
//void				ft_stat_error(char *file);
//int					add_link(t_lst **lst, t_init *in, char *file);
//int					sort_alpha(t_list **list);
//int					sort_time(t_lst **lst);
//int					add_link_arg(t_arg **arg, t_init *in, char *file);
//int					sort_alpha(t_arg **arg);
//int					sort_time(t_arg **arg);

#endif
