/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/06/27 11:08:11 by asalama          ###   ########.fr       */
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

void			arg_sort_alpha(t_arg **old_lst)
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
			if (ft_strcmp(runner->name, tmp->name) > 0)
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

void			sort_flags(t_flags *option, t_arg **arg_lst)
{
	if (option->t)
		arg_sort_time(arg_lst);
	else
		arg_sort_alpha(arg_lst);
	if (option->r)
		arg_sort_reverse(arg_lst);
}
