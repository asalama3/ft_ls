/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:11:26 by asalama           #+#    #+#             */
/*   Updated: 2016/03/30 19:45:52 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"


void	print(t_arg **arg)
{
	t_arg *runner;

	if (*arg)
	{
		runner = *arg;
		while (runner)
		{
			printf("%s -------", runner->argv);
			runner =  runner->next;
		}
	}
}


int		ft_stat(t_arg **arg, t_init *in, char *argv)
{
	if (!(in->buf = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	if ((stat(argv, in->buf)) == -1)
		return (-1);
		if (S_ISREG(in->buf->st_mode))
			printf("%s\n", argv);
//			printf("%li", in->buf->st_mtime);
	add_link_arg(arg, in, argv);
	return (0);
}

int			parse(t_init *in, int argc, char **argv, int k)
{
	t_arg			**arg;

//	ft_putendl(argv[k]);
	if(!(arg = (t_arg**)ft_memalloc(sizeof (t_arg*))))
		return (-1);
	while (k < argc)
	{
		if (!(in->dir = opendir(argv[k])))
		{
			if ((ft_stat(arg, in, argv[k]) == -1))
			{
//				ft_putendl("yftgf");
				ft_dir_error(argv[k]);
			}
		}
		if (in->dir)
		{
				ft_stat(arg, in, argv[k]);
/*			while ((in->ptr = readdir(in->dir)))
			{
				ft_putstr(in->ptr->d_name);
				ft_putchar('\n');
			}*/
			if (closedir(in->dir) == -1)
				ft_dir_error(argv[k]);
		}
		k++;
	}
	// Check et sort argvlist par fichiers ou dossiers et par alpha (ou flags)
	// SORT OK
	// 		while argv_list (qui est sort)
	// 			while readdir (arg->dir)
	// 				add_link_lst de dirent
	// 				sort;
	// 				print;
	// 				
	print(arg);
	return (0);
}

