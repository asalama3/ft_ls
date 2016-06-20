/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/06/20 21:12:46 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_path(char *dir, char *name)
{
	char	*path;
	int		length;
	int		slash;

	length = ft_strlen(dir);
	slash = dir[length - 1] == '/' ? 0 : 1;
	length = length + slash + ft_strlen(name);
	path = ft_strndup(dir, length + 1);
	if (slash)
		path[ft_strlen(dir)] = '/';
	path = ft_strcat(path, name);
//	printf("name: %s \n ", name);
//	printf("dir: %s\n  ", dir);
//	printf("path: %s \n", path);
	return (path);
}


int			make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option)
{
	t_arg	*link;

	while ((runner->ptr = readdir(runner->dir)) != NULL)
	{
		if ((link = link_malloc()) == NULL)
			return (-1);
		link->name = ft_strdup(runner->ptr->d_name);
		link->path = get_path(runner->name, runner->ptr->d_name);
		if (check_stat(link, runner->ptr->d_name) == -1)
			return (-1);
		else
			create_link_arg(link, &dir_lst);
//		runner = runner->next;
	}
//		printf("%s  NAME:\n", runner->name);
	sort_flags(option, &dir_lst);
	if (option->cap_r)
		rec(&dir_lst, option);
	print_arg_list(dir_lst);
	return(0);
}


void			rec(t_arg **dir_lst, t_flags *option)
{
	t_arg	*runner;

	runner = *dir_lst;
	while (runner != NULL)
	{
		if (S_ISDIR(runner->buf->st_mode) && ft_strcmp(runner->name, ".") != 0 && ft_strcmp(runner->name, "..") != 0)
		{
			print_file(runner);
			if ((runner->dir = opendir(runner->path)))
			{
//	ft_putendl(runner->name);
	ft_putendl("OK");
				make_dir(*dir_lst, runner, option);
				if (closedir(runner->dir) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}
			}
		}
		runner = runner->next;
	}
	print_arg_list(*dir_lst);
}

void			test_dir(t_arg **old_lst, t_flags *option)
{
	t_arg	*runner;
	t_arg	*dir_lst;

	runner = *old_lst;
	dir_lst = NULL;
	while (runner != NULL)
	{
		if (S_ISDIR(runner->buf->st_mode))
		{
			if ((runner->dir = opendir(runner->path)))
			{
				make_dir(dir_lst, runner, option);
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
