/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:39:39 by asalama           #+#    #+#             */
/*   Updated: 2016/07/07 17:40:24 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			create_link_arg(t_arg *link, t_arg **arg_lst)
{
	t_arg		*runner;

	if (*arg_lst)
	{
		runner = *arg_lst;
		while (runner->next)
			runner = runner->next;
		runner->next = link;
		link->next = NULL;
		link->prev = runner;
	}
	else
	{
		*arg_lst = link;
		link->prev = NULL;
		link->next = NULL;
	}
}

void			check_stat_link(char *file, t_arg *link)
{
	t_stat		*tmp;

	if (!(tmp = (t_stat*)ft_memalloc(sizeof(t_stat))))
		error_exit("Error malloc", EXIT_FAILURE);
	if (stat(file, tmp) == -1)
		free(tmp);
	link->buf->st_mode = tmp->st_mode;
	free(tmp);
}

int				check_stat(t_arg *link, char *file, t_flags *option)
{
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
		error_exit("Error malloc", EXIT_FAILURE);
	if ((lstat(file, link->buf)) == -1)
	{
		free(link->buf);
		link->buf = NULL;
	}
	else if (!option->l && S_ISLNK(link->buf->st_mode) == 1)
		check_stat_link(file, link);
	if ((!(link->path = ft_strdup(file))) ||
			(!(link->name = ft_strdup(file))))
	{
		if (link->path)
			free(link->path);
		free(link->buf);
		free(link);
		error_exit("Error malloc", EXIT_FAILURE);
	}
	return (0);
}

t_arg			*link_malloc(void)
{
	t_arg		*link;

	if (!(link = (t_arg*)ft_memalloc(sizeof(t_arg))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	return (link);
}

int				ft_ls(char **argv, t_flags option)
{
	t_arg		*arg_lst;
	t_arg		*link;
	t_arg		*error;

	arg_lst = NULL;
	while (*argv != NULL)
	{
		if ((link = link_malloc()) == NULL)
			return (-1);
		if (check_stat(link, *argv, &option) == -1)
			return (-1);
		else
			create_link_arg(link, &arg_lst);
		argv++;
	}
	sort_flags(&option, &arg_lst);
	error = error_list(&arg_lst);
	arg_sort_file_dir(&arg_lst);
//	printf("%p\n", arg_lst->buf);
//	print_arg_list(arg_lst, &option, NULL);
//	print_arg_list(error, &option, NULL);
	if (!option.l)
		test_file(&arg_lst);
	test_dir(&arg_lst, &option, error);
	return (0);
}
