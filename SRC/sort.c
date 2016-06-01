/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/06/01 14:22:06 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			arg_sort_file_dir(t_arg **old_lst)
{
	t_arg	*f_list;
//	t_arg	*d_list;
	t_arg	*runner;
	t_arg	*tmp;

	runner = *old_lst;
	*old_lst = (*old_lst)->next;

	printf("%s  first-runner\n", runner->name);
	while (*old_lst != NULL)
	{
		if (!S_ISDIR(runner->buf->st_mode))
		{
			printf("%s  FILE_OK\n", runner->name);
			f_list = runner;
			runner->next = NULL;
			runner->prev = NULL;
		}
		else
			runner = runner->next;
		tmp = *old_lst;
		*old_lst = (*old_lst)->next;
		printf("%s  TMP\n", tmp->name);
		if (!S_ISDIR(tmp->buf->st_mode))
		{
			printf("%s  TMP-OK_FILE\n", tmp->name);
			push_back(runner, tmp);
//			tmp = runner;
			runner = runner->next;
		}
		runner = f_list;
	}
	*old_lst = f_list;
}



void			arg_sort_reverse(t_arg **old_lst)
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
/*	if (option->r)
	{
		if (option->t)
		{
			arg_sort_time();
			arg_sort_reverse();
			DIR - FILE;
		}
		else
		{
			arg_sort_reverse();
			DIR - FILE;
		}
	}
	else if (option->t)
	{
		arg_sort_time();
		DIR - FILE;
	}
	else*/
	if (option->r)
//		arg_sort_reverse(arg_lst);
//	else if (!option->t)
//	{
//		arg_sort_alpha(arg_lst);
		arg_sort_file_dir(arg_lst);
//	}
//	else
//		arg_sort_time(arg_lst);
}
