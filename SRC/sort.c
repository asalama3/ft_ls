/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/05/27 18:07:30 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fonction sort alpha
// fonction sort time
// fonction sort files and dir
// fonction sort reverse

#include "ft_ls.h"

void			arg_sort_alpha_bis(t_arg **old_lst)
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
//				tmp->next = runner;
//				tmp->prev = runner->prev;
//				runner->prev = tmp;
				if (tmp->prev == NULL)
					new_lst = tmp;
				else
					tmp->prev->next = tmp;
				break ;
			}
			else if (runner->next == NULL)
			{
				push_back(runner, tmp);
//				tmp->next = NULL;
//				tmp->prev = runner;
//				runner->next = tmp;
				break ;
			}
			runner = runner->next;
		}
		runner = new_lst;
	}
	*old_lst = new_lst;
}








/*void			arg_sort_alpha(t_arg **arg_lst, t_arg *new)
{
	t_arg	*runner;
	t_arg	*next_runner;

	runner = *arg_lst;
	next_runner = runner->next;

	while (runner->next != NULL)
	{
		if (ft_strcmp(runner->name, next_runner->name) > 0)
		{
			next_runner->prev = runner->prev;
			runner->prev = next_runner;
			runner->next = next_runner->next;
			next_runner->next = runner;
			next_runner = runner->next;
		}
		else
		{
			runner = runner->next;
			next_runner = runner->next;
		}
	}
	print_arg_list(arg_lst);
}
*/


void			arg_sort_time(t_arg **arg_lst)
{

}
