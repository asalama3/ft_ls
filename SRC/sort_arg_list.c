/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:51:29 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 22:20:38 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TIME_S buf->st_mtimespec.tv_sec
#define TIME_NS buf->st_mtimespec.tv_nsec

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
		tmp = *old_lst;
		*old_lst = (*old_lst)->next;
		position_front(runner, tmp);
		if (tmp->prev == NULL)
			new_lst = tmp;
		runner = new_lst;
	}
	*old_lst = new_lst;
}

void			free_old_lst(t_arg **old_lst)
{
	t_arg	*runner;
	t_arg	*tmp;

	runner = *old_lst;
	if (!runner)
		return ;
	if (!runner->next)
	{
		free(runner);
		return ;
	}
	while (runner != NULL)
	{
		tmp = runner;
		runner = runner->next;
		free(tmp);
	}
}
int				t_pos(t_arg **runner, t_arg **tmp, t_arg **new_lst)
{
	position_front(*runner, *tmp);
	if ((*tmp)->prev == NULL)
		*new_lst = *tmp;
	else
		if ((*tmp)->prev != NULL)
			position_insert(*tmp);
	return (1);
}


void			check_time(t_arg *runner, t_arg *tmp, t_arg **new_lst)
{
//	tmp = *old_lst;
//	*old_lst = (*old_lst)->next;
	while (runner != NULL)
	{
//		printf("%p\n", tmp->buf);
		if (runner->buf && tmp->buf && runner->TIME_S != tmp->TIME_S)
		{
			if (runner->TIME_S < tmp->TIME_S && t_pos(&runner, &tmp, new_lst))
				break ;
			else if (runner->next == NULL && position_back(runner, tmp))
				break ;
		}
		else if (runner->buf && tmp->buf && runner->TIME_NS != tmp->TIME_NS)
		{
			if (runner->TIME_NS < tmp->TIME_NS && t_pos(&runner, &tmp, new_lst))
				break ;
			else if (runner->next == NULL && position_back(runner, tmp))
				break ;
		}
		else
			if (ft_strcmp(runner->name, tmp->name) > 0 && t_pos(&runner, &tmp, new_lst))
				break ;
			else if (runner->next == NULL && position_back(runner, tmp))
				break ;
		runner = runner->next;
		}
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
		check_time(runner, tmp, &new_lst);
/*		while (runner != NULL)
		{
			if (tmp->buf && runner->TIME_S != tmp->TIME_S)
			{
				if (runner->TIME_S < tmp->TIME_S && fanny(&runner, &tmp, &new_lst))
					break ;
				else if (runner->next == NULL && position_back(runner, tmp))
					break ;
			}
			else if (tmp->buf && runner->TIME_NS != tmp->TIME_NS)
			{
				if (runner->TIME_NS < tmp->TIME_NS && fanny(&runner, &tmp, &new_lst))
					break ;
				else if (runner->next == NULL && position_back(runner, tmp))
					break ;
			}
			else
				if (ft_strcmp(runner->name, tmp->name) > 0 && fanny(&runner, &tmp, &new_lst))
					break ;
				else if (runner->next == NULL && position_back(runner, tmp))
					break ;
			runner = runner->next;
		}*/
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
