/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:08:57 by asalama           #+#    #+#             */
/*   Updated: 2016/06/30 20:20:29 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_arg_list(t_arg *lst, t_flags *option, t_file *file)
{
	t_arg	*runner;
	
	if (lst != NULL)
	{
		runner = lst;
		while (runner != NULL)
		{
			if (option->l)
			{
				l_info(runner, file);
				print_l_info(file);
			}
			else
			ft_putendl(runner->name);
			runner = runner->next;
		}
//		if (list_en(&arg_lst) > 1 && S_ISDIR(runner->buf->st_mode))
//			ft_putstr("\n");
//		write(1, "\n", 1);
	}
}

//void		print_empty_line(t_arg *runner, 

void		print_file(t_arg *runner)
{
	char	*tmp;

	if (!(tmp = ft_strdup(runner->path)))
		exit(EXIT_FAILURE);
	ft_putstr("\n");
	ft_putstr(tmp);
	write (1, ":\n", 2);
	free (tmp);
}

void		print_total(t_file *file)
{
		ft_putstr("total ");
		ft_putnbr(file->nb_blocks);
		ft_putstr("\n");
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
