/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/06/03 18:53:48 by asalama          ###   ########.fr       */
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
		push_back(runner, &f_list);
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
			push_back(tmp, &f_list);
			tmp = runner;
		}
		else
			tmp = tmp->next;
	}
	join_file_dir(old_lst, f_list);
}
