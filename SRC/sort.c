/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/05/24 17:39:43 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//fonction sort alpha
// fonction sort time
// fonction sort files and dir
// fonction sort reverse

#include "ft_ls.h"

void			arg_sort_alpha_bis(t_arg **arg_lst)
{
	t_arg	*runner;
	t_arg	*tmp;

	runner = *arg_lst;
	tmp = runner->next;
	runner->next = NULL;
	runner->prev = NULL;
	
	while (runner != NULL)
	{
		//2eme boucle while tant que ma 2eme liste nest pas finie)
		if (ft_strcmp(runner->name, tmp->name) > 0)
		{
			tmp->next = runner;
			tmp->prev = runner->prev;
			tmp->prev->next = tmp;
			runner->prev = tmp;
		}
		else
			runner = runner->next;
	}
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


void			arg_sort_time(t_arg **arg_lst, t_arg *link)
{

}
