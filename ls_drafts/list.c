/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:32:06 by asalama           #+#    #+#             */
/*   Updated: 2016/05/11 11:20:07 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int         add_link(t_lst **lst, t_init *in, char *file)
{
    t_lst	*new;
    t_lst	*runner;

	if ((new = (t_lst*)malloc(sizeof (t_lst))))
	{
		new->file = file;
		new->init = in;
		if (*lst)
		{
			runner = *lst;
			while (runner->next)
				runner = runner->next;
			runner->next = new;
			new->next = NULL;
			new->prev = runner;
		}
		else
		{
			*lst = new;
			new->prev = NULL;
			new->next = NULL;
		}
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}


int			sort_alpha(t_lst **lst)
{
	t_lst	*runner;
	t_lst	*tmp;

	if (*lst)
	{
		runner = *lst;
		while(runner)
		{
			if ((ft_strcmp(runner->file, runner->next->file)) > 0)
			{
				tmp = runner;
				runner = runner->next;
				runner->next = tmp;
				runner = *lst;
			}
			runner = runner->next;
		}
	}
	else
		return (-1);
	return (0);
}


int			sort_time(t_lst **lst)
{
	t_lst	*runner;
	t_lst	*tmp;

	if (*lst)
	{
		runner = *lst;
		while(runner)
		{
			if (runner->init->buf->st_mtime < runner->next->init->buf->st_mtime)
			{
				tmp = runner;
				runner = runner->next;
				runner->next = tmp;
				runner = *lst;
			}
			runner = runner->next;
		}
	}
	else
		return (-1);
	return (0);
}
