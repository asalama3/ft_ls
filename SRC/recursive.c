/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/06/27 17:14:01 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_path(char *dir, char *name)
{
	char	*path;
/*	int		length;
	int		slash;

	length = ft_strlen(dir);
	slash = dir[length - 1] == '/';
	length = length + slash + ft_strlen(name);
	path = ft_strndup(dir, length + 1);
//	if (slash)
		path[ft_strlen(dir)] = '/';
	path = ft_strcat(path, name);
*/
	path = ft_strjoin(dir, "/");
	path = ft_strjoin(path, name);
//	printf("name: %s \n ", name);
//	printf("dir: %s\n  ", dir);
//	printf("path: %s \n", path);
	return (path);
}

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

int			make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option, t_file *file)
{
	t_arg	*link;

	while ((runner->ptr = readdir(runner->dir)) != NULL)
	{
		if ((link = link_malloc()) == NULL)
			return (-1);
		link->name = ft_strdup(runner->ptr->d_name);
		link->path = get_path(runner->path, link->name);
//		printf("\n%s", link->path);
		if (check_file(link, link->path) == -1)
			return (-1);
		else
		{
			create_link_arg(link, &dir_lst);
		}
	sort_flags(option, &dir_lst);
		if (option->l)
		{
			l_info(link, file);
//			print_l_info(file);
		}
	}
/*	t_arg *tmp;
	tmp = dir_lst;
	while (tmp)
	{
		printf("\n%s", tmp->name);
//		print_l_info(tmp, file);
		tmp = tmp->next;
	}
	printf("\n*********************\n");*/

//	printf("%s  NAME:\n", runner->name);
	if (option->cap_r)
		rec(dir_lst, option, file);
	print_arg_list(dir_lst);
	return(0);
}

void			rec(t_arg *dir_lst, t_flags *option, t_file *file)
{
	t_arg	*runner;
	t_arg	*ptr;

	ptr = NULL;
	runner = dir_lst;
//	ft_putendl(runner->path);
	while (runner != NULL)
	{
		if (S_ISDIR(runner->buf->st_mode) && ft_strcmp(runner->name, ".") != 0 
				&& ft_strcmp(runner->name, "..") != 0)
		{
//			printf("\n%s/%s \n", runner->name, runner->path);
			print_file(runner);
			if ((runner->dir = opendir(runner->path)))
			{
//	ft_putendl(runner->name);
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
//	print_arg_list(*dir_lst);
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
		if (option->l)
		{
			l_info(runner, file);
//			print_l_info(file);
		}
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
