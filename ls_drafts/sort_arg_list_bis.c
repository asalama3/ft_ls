/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:51:29 by asalama           #+#    #+#             */
/*   Updated: 2016/06/29 22:55:58 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			arg_sort_reverse(t_arg **old_lst)
{
	t_arg	*runner;
	t_arg	*tmp;
	t_arg	*new_lst;

	runner = *old_lst;
	*old_lst = (*old_lst)->next;
	new_lst = runner;
	init_lst(runner);

	while (*old_lst != NULL)
	{
//		printf("%s runner\n", runner->name);
		tmp = *old_lst;
		*old_lst = (*old_lst)->next;
		position_front(runner, tmp);
//		printf("%s tmp\n", tmp->name);
		if (tmp->prev == NULL)
			new_lst = tmp;
		runner = new_lst;
	}	
	*old_lst = new_lst;
}

void			arg_sort_time(t_arg **old_lst)
{
	t_arg	*runner;
	t_arg	*tmp;
	t_arg	*new_lst;

	runner = *old_lst;
	*old_lst = (*old_lst)->next;
	new_lst = runner;
	runner->next = NULL;
	runner->prev = NULL;
	
	while (*old_lst != NULL)
	{
		tmp = *old_lst;
		*old_lst = (*old_lst)->next;
		while (runner != NULL)
		{
			if (runner->buf->st_mtime < tmp->buf->st_mtime)
			{
				position_front(runner, tmp);
				if (tmp->prev == NULL)
					new_lst = tmp;
				else
				if (tmp->prev != NULL)
					position_insert(tmp);
				break ;
			}
			else if (runner->next == NULL)
			{
				position_back(runner, tmp);
				break ;
			}
			runner = runner->next;
		}
		runner = new_lst;
	}
	*old_lst = new_lst;
}

void			arg_sort_alpha_bis(t_arg *link, t_arg **arg_lst)
{
	t_arg	*runner;

	runner = *arg_lst;
	if (ft_strcmp(runner->name, link->name) > 0)
	{
		link->next = runner;
		runner->prev = link;
		*arg_lst = link;
		return ;
	}
	while (runner != NULL && runner->next != NULL)
	{
		if ((ft_strcmp(runner->name, link->name) <= 0) 
				&& ft_strcmp(runner->next->name, link->name) >= 0)
		{
			link->next = runner->next;
			runner->next = link;
			link->prev = runner;
			link->next->prev = link;
			return ;
		}
		runner = runner->next;
	}
	link->prev = runner;
	runner->next = link;
}
