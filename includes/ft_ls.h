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

#include <stdio.h>

typedef struct		s_init
{
	struct dirent	*ptr;
	DIR				*dir;
}					t_init;


typedef struct		s_flags
{
	int				R;
	int				r;
	int				a;
	int				t;
	int				l;
}					t_flags;

int					parse(t_init *in, int argc, char **argv, int k);
void				ft_error(char option);
void				ft_dir_error(char *file);


#endif
