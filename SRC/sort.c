/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:50:38 by asalama           #+#    #+#             */
/*   Updated: 2016/05/25 18:19:07 by asalama          ###   ########.fr       */
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
		while (runner != NULL)
		{
			//tant que ma 2eme liste nest pas finie..
			// si runner->prev == NULL?? crash
			// si runner->next == NULL?? crash
			if (ft_strcmp(runner->name, tmp->name) > 0)
			{
				ft_putendl("front");
				if (runner->prev == NULL)
				{
					tmp->prev = NULL;
					tmp->next = runner;
					runner->prev = tmp;
				}
				tmp->next = runner;
				tmp->prev = runner->prev;
				tmp->prev->next = tmp;
				runner->prev = tmp;
			}
			else
			{
				runner = runner->next;
				ft_putendl("back");
				if (runner->next == NULL)
				{
					tmp->next = NULL;
					tmp->prev = runner;
					runner->next = tmp;
				}
//				tmp->next = runner->next;
//				tmp->prev = runner;
//				runner->next->prev = tmp;
//				tmp->next->prev = tmp;
//				runner->next = tmp;
//				runner = runner->next;
			}
			// pointe sur le debut de la liste ?
//			runner = *arg_lst;
//			runner = runner->next;
		}
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
