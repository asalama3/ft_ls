/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 17:43:30 by asalama           #+#    #+#             */
/*   Updated: 2016/07/08 10:54:53 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_error_list(t_arg **error_lst, t_arg *runner)
{
	if (error_lst)
	{
		runner = *error_lst;
		while (runner)
		{
			ft_stat_error(runner->name);
			runner = runner->next;
		}
	}
}

t_arg		*err(t_arg *runner, t_arg *error_lst, t_arg **old_lst)
{
	t_arg	*tmp;

	runner = *old_lst;
	tmp = runner;
	while (tmp != NULL)
	{
		if (tmp->buf == NULL)
		{
			runner = tmp->next;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			push_back(tmp, &error_lst);
			tmp = runner;
		}
		else
			tmp = tmp->next;
	}
	return (error_lst);
}

t_arg		*error_list(t_arg **old_lst)
{
	t_arg	*runner;
	t_arg	*error_lst;

	runner = *old_lst;
	error_lst = NULL;
	while ((runner != NULL && runner->buf == NULL))
	{
		*old_lst = (*old_lst)->next;
		push_back(runner, &error_lst);
		runner = *old_lst;
	}
	error_lst = err(runner, error_lst, old_lst);
	print_error_list(&error_lst, runner);
	return (error_lst);
}
