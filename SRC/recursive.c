/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/07/01 18:59:08 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_path(char *dir, char *name)
{
	char	*path;
	char	*tmp;
	
	path = ft_strjoin(dir, "/");
	tmp = path;
	path = ft_strjoin(path, name);
	free (tmp);
	return (path);
}

int			check_file(t_arg *link, char *file, t_flags *option)
{
	t_stat		*tmp;

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
	if (!option->l && S_ISLNK(link->buf->st_mode) == 1)
	{
//		printf("tata");
		if (!(tmp = (t_stat*)ft_memalloc(sizeof(t_stat))))
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		if (stat(file, tmp) == -1)
			free(tmp);
		link->buf->st_mode = tmp->st_mode;
		free(tmp);
	}
	return (0);
}

int			make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option, t_file *file)
{
	t_arg	*link;
	file->nb_blocks = 0;
	
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
		if (check_file(link, link->path, option) == -1)
			return (-1);
		else
		{
			create_link_arg(link, &dir_lst);
		}
		sort_flags(option, &dir_lst);
		if (option->l)
		{
			total(link, file);
		}
	}
	if (option->l)
		print_total(file);
	print_arg_list(dir_lst, option, file);
	if (option->cap_r)
		rec(dir_lst, option, file);
	return(0);
}

void			rec(t_arg *dir_lst, t_flags *option, t_file *file)
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
			{
				l_info(runner, file);
				total(runner, file);
			}
			print_file(runner);
			if ((runner->dir = opendir(runner->path)))
			{
				make_dir(ptr, runner, option, file);
				if (closedir(runner->dir) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}
			}
		}
		runner = runner->next;
	}
}

void			test_dir(t_arg **old_lst, t_flags *option)
{
	t_arg	*runner;
	t_arg	*dir_lst;
	t_file	*file;

	runner = *old_lst;
	dir_lst = NULL;
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	while (runner != NULL)
	{
		if (option->l && !S_ISDIR(runner->buf->st_mode))
		{
			l_info(runner, file);
			print_l_info(file);
		}
	if (list_len(old_lst) > 1 && (S_ISDIR(runner->buf->st_mode) || S_ISLNK(runner->buf->st_mode)))
		print_file(runner);
			if (S_ISDIR(runner->buf->st_mode))
		{
			if ((runner->dir = opendir(runner->path)))
			{
				make_dir(dir_lst, runner, option, file);
			}
			if (closedir(runner->dir) == -1)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}
		runner = runner->next;
		}
	else
		runner = runner->next;
	}
}

void			test_file(t_arg **old_lst)
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

