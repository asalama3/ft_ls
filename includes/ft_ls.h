/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/03/30 19:46:00 by asalama          ###   ########.fr       */
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



typedef struct		s_init
{
	struct dirent	*ptr;
	DIR				*dir;
	struct stat		*buf;
}					t_init;

typedef struct		s_flags
{
	int				R;
	int				r;
	int				a;
	int				t;
	int				l;
}					t_flags;

typedef struct		s_lst
{
//	t_flags         *flags;
	t_init			*init;
    char			*file;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_arg
{
	t_init			*init;
	char			*argv;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;



int					parse(t_init *in, int argc, char **argv, int k);
void				ft_error(char option);
void				ft_dir_error(char *file);
void				ft_stat_error(char *file);
int					add_link(t_lst **lst, t_init *in, char *file);
int					add_link_arg(t_arg **arg, t_init *in, char *file);



#endif
