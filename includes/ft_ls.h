/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:54:51 by asalama           #+#    #+#             */
/*   Updated: 2016/03/24 17:18:36 by asalama          ###   ########.fr       */
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

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1


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
	char			*file;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;



int					parse(t_init *in, int argc, char **argv, int k);
void				ft_error(char option);
void				ft_dir_error(char *file);
void				ft_stat_error(char *file);


#endif
