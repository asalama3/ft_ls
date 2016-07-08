/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_flags_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 12:29:24 by asalama           #+#    #+#             */
/*   Updated: 2016/07/08 13:03:01 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
				else if (tmp->prev != NULL)
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
