/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:08:57 by asalama           #+#    #+#             */
/*   Updated: 2016/06/28 13:34:08 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_arg_list(t_arg *lst)
{
	t_arg	*runner;
	
	if (lst != NULL)
	{
		runner = lst;
//		ft_putendl("///////ARGV LIST //////////");
		while (runner)
		{
			ft_putendl(runner->name);
			runner = runner->next;
		}
		write(1, "\n", 1);
	}
}

void		print_file(t_arg *runner)
{
	char	*tmp;

//	ft_putendl(runner->path);
	if (!(tmp = ft_strdup(runner->path)))
		exit(EXIT_FAILURE);
//	write (1, "\n: ", 2);
	ft_putstr(tmp);
	write (1, ":", 1);
	free (tmp);
}

void		print_l_info(t_file *file)
{
		ft_putstr(file->rights);
		ft_putstr(" ");
		ft_putnbr(file->nb_hlink);
		ft_putstr(" ");
		ft_putstr(file->pw_name);
		ft_putstr(" ");
		ft_putstr(file->gr_name);
		ft_putstr(" ");
		ft_putnbr(file->size);
		ft_putstr(" ");
		ft_putstr(file->time_date);
		ft_putstr(" ");
		ft_putstr(file->file_name);
		ft_putstr("\n");
}
