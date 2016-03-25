/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:11:26 by asalama           #+#    #+#             */
/*   Updated: 2016/03/26 00:12:32 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"


void	print(t_lst **lst)
{
	t_lst *runner;

	if (*lst)
	{
		runner = *lst;
		while (runner)
		{
			printf("%s -------", runner->file);
			runner =  runner->next;
		}
	}
}


int		ft_stat(t_lst **lst, t_init *in, char *argv)
{
	if (!(in->buf = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	if ((stat(argv, in->buf)) == -1)
		return (-1);
		if (S_ISREG(in->buf->st_mode))
			printf("%s\n", argv);
//			printf("%li", in->buf->st_mtime);
	add_link(lst, in, argv);
	return (0);
}

int			parse(t_init *in, int argc, char **argv, int k)
{
	t_lst			**lst;

//	ft_putendl(argv[k]);
	if(!(lst = (t_lst**)ft_memalloc(sizeof (t_lst*))))
		return (-1);
	while (k < argc)
	{
		if (!(in->dir = opendir(argv[k])))
		{
			if ((ft_stat(lst, in, argv[k]) == -1))
			{
//				ft_putendl("yftgf");
				ft_dir_error(argv[k]);
			}
		}
		if (in->dir)
		{
				ft_stat(lst, in, argv[k]);
			while ((in->ptr = readdir(in->dir)))
			{
		//		ft_putstr(in->ptr->d_name);
			//	ft_putchar('\n');
			}
			if (closedir(in->dir) == -1)
				ft_dir_error(argv[k]);
		}
		k++;
	}
	print(lst);
	return (0);
}

