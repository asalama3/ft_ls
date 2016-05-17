/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:39:39 by asalama           #+#    #+#             */
/*   Updated: 2016/05/17 17:57:31 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			link_arg(t_arg *link, t_arg **arg_lst)
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

static int		call_stat(t_arg *link, char *file, t_flags *option, t_arg **arg_lst)
{
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if ((stat(file, link->buf)) == -1)
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
//	ft_putendl("OKKKKKKKK");
	return (0);
}

t_arg		*get_av_list(char **argv, t_flags option, t_arg **arg_lst)
{
	t_arg		*link;
	
	if (!(link = (t_arg*)ft_memalloc(sizeof(t_arg))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	return (link);
}

int		ft_ls(char **argv, t_flags option)
{
	t_arg	*arg_lst;
	t_arg	*link;

	arg_lst = NULL;
//	if (!(arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg))))
//		return (-1);
	while (*argv != NULL)
	{
		ft_putendl("-----");
		if ((link = get_av_list(argv, option, &arg_lst)) == NULL)
			return (-1);
		if (call_stat(link, *argv, &option, &arg_lst) == -1)
		{
			//error_list();
			return (-1);
		}
		link_arg(link, &arg_lst);
		argv++;
	}
	print_av_list(arg_lst);
	return (0);
}
