/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:41:01 by asalama           #+#    #+#             */
/*   Updated: 2016/05/13 17:11:13 by asalama          ###   ########.fr       */
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
			printf("lst count: %d\n", n);
		}
		return (n);
	}
	return (0);
}

void	push_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	push_back(t_arg *runner, t_arg *new)
{
	runner->next = new;
	new->prev = runner;
}

