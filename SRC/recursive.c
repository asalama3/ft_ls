/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/07/07 17:40:21 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_file(t_arg *link, char *file)
{
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if ((lstat(file, link->buf)) == -1)
	{
		free(link->buf);
		link->buf = NULL;
	}
	return (0);
}

void		options_and_print(t_flags *option, t_file *file, t_arg *dir_lst)
{
	if (option->l)
		print_total(file);
	print_arg_list(dir_lst, option, file);
	if (option->cap_r)
		rec(dir_lst, option, file);
}

int			make_d(t_arg *dir_lst, t_arg *runner, t_flags *option, t_file *file)
{
	t_arg	*link;

	while ((runner->ptr = readdir(runner->dir)) != NULL)
	{
		if (!option->a && (runner->ptr->d_name[0] == '.' ||
					(ft_strcmp(".", runner->ptr->d_name) == 0) ||
					ft_strcmp("..", runner->ptr->d_name) == 0))
			continue ;
		if ((link = link_malloc()) == NULL)
			return (-1);
		link->name = ft_strdup(runner->ptr->d_name);
		link->path = get_path(runner->path, link->name);
		if (check_file(link, link->path) == -1)
			return (-1);
		else
			create_link_arg(link, &dir_lst);
		sort_flags(option, &dir_lst);
		if (option->l)
			total(link, file);
	}
	options_and_print(option, file, dir_lst);
	return (0);
}

void		info_and_total_l(t_arg *runner, t_file *file)
{
	l_info(runner, file);
	total(runner, file);
}

void		rec(t_arg *dir_lst, t_flags *option, t_file *file)
{
	t_arg	*runner;
	t_arg	*ptr;

	ptr = NULL;
	runner = dir_lst;
	while (runner != NULL)
	{
		if (S_ISDIR(runner->buf->st_mode) && ft_strcmp(runner->name, ".") != 0
				&& ft_strcmp(runner->name, "..") != 0)
		{
			if (option->l)
				info_and_total_l(runner, file);
			print_file(runner);
			if (!(runner->dir = opendir(runner->path)))
			{
				ft_putstr(runner->path);
				ft_putstr(": ");
				ft_putstr(strerror(errno));
				ft_putstr("\n");
			}
			else
			{
				make_d(ptr, runner, option, file);
				if (closedir(runner->dir) == -1)
					error_exit("Error Malloc", EXIT_FAILURE);
			}
		}
		runner = runner->next;
	}
}
