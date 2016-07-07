/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/07/07 17:40:19 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		info_and_print_l(t_arg *runner, t_file *file)
{
	l_info(runner, file);
	print_l_info(file);
}

void		dir_ok(t_arg *runner, t_arg *dir_lst, t_flags *option, t_file *file)
{
	if (!(runner->dir = opendir(runner->path)))
	{
		ft_putstr(runner->path);
		ft_putstr(":");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	else
	{
		make_d(dir_lst, runner, option, file);
		if (closedir(runner->dir) == -1)
			error_exit("Error Malloc", EXIT_FAILURE);
	}
}

void		test_dir(t_arg **old_lst, t_flags *option, t_arg *error_lst)
{
	t_arg	*runner;
	t_arg	*dir_lst;
	t_file	*file;

	runner = *old_lst;
	dir_lst = NULL;
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
		error_exit("Error malloc", EXIT_FAILURE);
	while (runner != NULL)
	{
		if (option->l && !S_ISDIR(runner->buf->st_mode))
			info_and_print_l(runner, file);
		if (((list_len(old_lst) > 1 || error_lst))
				&& (S_ISDIR(runner->buf->st_mode)))
			print_file(runner);
		if (S_ISDIR(runner->buf->st_mode))
		{
			dir_ok(runner, dir_lst, option, file);
			runner = runner->next;
		}
		else
			runner = runner->next;
	}
}

void		test_file(t_arg **old_lst)
{
	t_arg	*runner;
	t_arg	*dir_lst;

	runner = *old_lst;
	dir_lst = NULL;
	while (runner != NULL)
	{
		if (!S_ISDIR(runner->buf->st_mode) && !S_ISLNK(runner->buf->st_mode))
		{
			ft_putstr(runner->name);
			ft_putstr("\n");
		}
		runner = runner->next;
	}
}
