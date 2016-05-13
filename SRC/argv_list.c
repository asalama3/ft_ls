/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:39:39 by asalama           #+#    #+#             */
/*   Updated: 2016/05/13 19:32:00 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		argv_list_time(t_arg **lst, t_arg *new)
{
	t_arg *runner;

	if (*lst)
	{
//	ft_putendl(new->name);
		runner = *lst;
		if (list_len(lst) == 1)
		{
//			ft_putendl(new->name);
			((S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) == 1) || ((S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) != 1 && runner->buf->st_mtime > new->buf->st_mtime))) ? push_front(lst, new) : push_back(runner, new);
		}
			else
		{
			ft_putendl("heyyyyy");
			if (S_ISDIR(new->buf->st_mode) != 1)
				while (runner->next && S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) != 1 && runner->buf->st_mtime < new->buf->st_mtime)
					runner = runner->next;
			else if (S_ISDIR(new->buf->st_mode) == 1)
				while (runner->next && ((S_ISDIR(runner->buf->st_mode) != 1 || (((new->buf->st_mode) == (runner->buf->st_mode)) && runner->buf->st_mtime > new->buf->st_mtime))))
					runner = runner->next;
			if (runner->prev == NULL)
				push_front(lst, new);
			else if ((runner->next == NULL && S_ISDIR(runner->buf->st_mode) != 1 && S_ISDIR(new->buf->st_mode) != 1 && (runner->buf->st_mtime < new->buf->st_mtime)) || (S_ISDIR(runner->buf->st_mode) != 1 && S_ISDIR(new->buf->st_mode) == 1))
				push_back(runner, new);
		}
	}
	else
		*lst = new;
}

static void		argv_list_alpha(t_arg **lst, t_arg *new)
{
	t_arg *runner;

	if (*lst)
	{
	ft_putendl(new->name);
		runner = *lst;
		if (list_len(lst) == 1)
		{
			ft_putendl(new->name);
			((S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) == 1) || ((S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) != 1 && ft_strcmp(runner->name, new->name) > 0))) ? push_front(lst, new) : push_back(runner, new);
		}
			else
		{
			ft_putendl("heyyyyy");
			if (S_ISDIR(new->buf->st_mode) != 1)
				while (runner->next && S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) != 1 && (ft_strcmp(runner->name, new->name) < 0))
					runner = runner->next;
			else if (S_ISDIR(new->buf->st_mode) == 1)
				while (runner->next && ((S_ISDIR(runner->buf->st_mode) != 1 || (((new->buf->st_mode) == (runner->buf->st_mode)) && ft_strcmp(runner->name, new->name) < 0))))
					runner = runner->next;
			if (runner->prev == NULL)
				push_front(lst, new);
			else if ((runner->next == NULL && S_ISDIR(runner->buf->st_mode) != 1 && S_ISDIR(new->buf->st_mode) != 1 && ft_strcmp(runner->name, new->name) < 0) || (S_ISDIR(runner->buf->st_mode) != 1 && S_ISDIR(new->buf->st_mode) == 1))
				push_back(runner, new);
		}
	}
	else
		*lst = new;
}

static int		call_stat(t_arg *link, char *file, t_flags *option, t_arg *arg_lst)
{
//	t_arg		**arg_lst;
	
//	if (!(arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg))))
//	{
//		perror("error malloc");
//		exit(EXIT_FAILURE);
//	}
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if ((lstat(file, link->buf)) == -1)
	{
		free(link->buf);
		free(link);
		return (-1);
	}
	if ((!(link->path = ft_strdup(file))) || (!(link->name = ft_strdup(file))))
	{
		if (link->path)
			free(link->path);
		free(link->buf);
		free(link);
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	ft_putendl("lllll");
	link->prev = NULL;
	link->next = NULL;
	if (!option->t)
	{	
		argv_list_alpha(&arg_lst, link);
	}
	else
		argv_list_time(&arg_lst, link);
	return (0);
}

int		get_av_list(char **argv, t_flags option, t_arg *arg_lst)
{
	t_arg		*link;
	
	if (!(link = (t_arg*)ft_memalloc(sizeof(t_arg))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	ft_putendl("hhhhhhhhhhhhhhhh");
	if (call_stat(link, *argv, option, arg_lst) != -1)
		return (0);
	else
	{
//		error_list();
		return (-1);
	}
	return (0);
}

int		ft_ls(char **argv, t_flags option)
{
	t_arg	*arg_lst;

	if (!(arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg))))
		return (-1);
	while (argv[i])
»···if (get_av_list(argv, option, arg_lst) == -1)
		return (-1);
}
