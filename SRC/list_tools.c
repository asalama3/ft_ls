/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:41:01 by asalama           #+#    #+#             */
/*   Updated: 2016/06/30 14:26:01 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		list_len(t_arg **lst)
{
	t_arg	*runner;
	int		n;

	if (*lst)
	{
		n = 0;
		runner = *lst;
		while (runner)
		{
			n++;
			runner = runner->next;
//			printf("lst count: %d\n", n);
		}
		return (n);
	}
	return (0);
}

void	init_lst(t_arg *runner)
{
	if (runner->prev != NULL)
		runner->prev->next = runner->next;
	if (runner->next != NULL)
		runner->next->prev = runner->prev;
	runner->next = NULL;
	runner->prev = NULL;
}

void	push_back(t_arg *runner, t_arg **begin_lst)
{
	t_arg	*link;

	if (*begin_lst)
	{
		link = *begin_lst;
		while(link->next != NULL)
			link = link->next;
		runner->next = NULL;
		runner->prev = link;
		runner->prev->next = runner;
	}
	else
	{
		init_lst(runner);
		*begin_lst = runner;
	}
}
