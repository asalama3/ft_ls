/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_argc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:32:06 by asalama           #+#    #+#             */
/*   Updated: 2016/05/11 14:10:10 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int         add_link_arg(t_arg **arg, t_init *in, char *file)
{
	t_arg	*new;
	t_arg	*runner;

	if ((new = (t_arg*)malloc(sizeof (t_arg))))
	{
		new->argv = file;
		new->init = in;
		if (*arg)
		{
			runner = *arg;
			while (runner->next)
				runner = runner->next;
			runner->next = new;
			new->next = NULL;
			new->prev = runner;
		}
		else
		{
			*arg = new;
			new->prev = NULL;
			new->next = NULL;
		}
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}


int			sort_alpha(t_arg **arg)
{
	t_arg	*runner;
	t_arg	*tmp;

	if (*arg)
	{
		runner = *arg;
		while(runner)
		{
			if ((ft_strcmp(runner->argv, runner->next->argv)) > 0)
			{
				tmp = runner;
				runner = runner->next;
				runner->next = tmp;
				runner = *arg;
			}
			runner = runner->next;
		}
	}
	else
		return (-1);
	return (0);
}


int			sort_time(t_arg **arg)
{
	t_arg	*runner;
	t_arg	*tmp;

	if (*arg)
	{
		runner = *arg;
		while(runner)
		{
			if (runner->init->buf->st_mtime < runner->next->init->buf->st_mtime)
			{
				tmp = runner;
				runner = runner->next;
				runner->next = tmp;
				runner = *arg;
			}
			runner = runner->next;
		}
	}
	else
		return (-1);
	return (0);
}
