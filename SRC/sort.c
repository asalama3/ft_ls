/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/06/03 10:01:08 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void			join_file_dir(t_arg **old_lst, t_arg *f_list)
{
	t_arg	*tmp;

	tmp = f_list;
	if (f_list != NULL)
	{
		while (f_list->next != NULL)
			f_list = f_list->next;
		f_list->next = *old_lst;
		if (*old_lst != NULL)
			(*old_lst)->prev = f_list;
		(*old_lst) = tmp;
	}
}

void			arg_sort_file_dir(t_arg **old_lst)
{
	t_arg	*f_list;
	t_arg	*runner;
	t_arg	*tmp;

	runner = *old_lst;
	f_list = NULL;
	while (runner != NULL && !S_ISDIR(runner->buf->st_mode))
	{
		*old_lst = (*old_lst)->next;
		push_back_bis(runner, &f_list);
		runner = *old_lst;
	}
	tmp = runner; 
	while (tmp != NULL)
	{
		if (!S_ISDIR(tmp->buf->st_mode))
		{
			runner = tmp->next;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			push_back_bis(tmp, &f_list);
			tmp = runner;
		}
		else
			tmp = tmp->next;
	}
	join_file_dir(old_lst, f_list);
}


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
		push_front(runner, tmp);
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
				push_front(runner, tmp);
				if (tmp->prev == NULL)
					new_lst = tmp;
				else
				if (tmp->prev != NULL)
					push_insert(tmp);
				break ;
			}
			else if (runner->next == NULL)
			{
				push_back(runner, tmp);
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
				push_front(runner, tmp);
				if (tmp->prev == NULL)
					new_lst = tmp;
				else
				if (tmp->prev != NULL)
					push_insert(tmp);
				break ;
			}
			else if (runner->next == NULL)
			{
				push_back(runner, tmp);
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
	if (option->r)
	{
		if (option->t)
		{
			arg_sort_time(arg_lst);
			arg_sort_reverse(arg_lst);
		}
		else
		{
			arg_sort_reverse(arg_lst);
		}
	}
	else if (option->t)
		arg_sort_time(arg_lst);
	else
	{
		if (!option->t)
		{
			arg_sort_alpha(arg_lst);
			arg_sort_file_dir(arg_lst);
		}
		else
			arg_sort_time(arg_lst);
	}
}
