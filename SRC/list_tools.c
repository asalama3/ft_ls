/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:41:01 by asalama           #+#    #+#             */
/*   Updated: 2016/06/01 13:49:11 by asalama          ###   ########.fr       */
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

void	push_front(t_arg *runner, t_arg *tmp)
{
	tmp->next = runner;
	tmp->prev = runner->prev;
	runner->prev = tmp;
}

void	push_back(t_arg *runner, t_arg *tmp)
{
//	printf("%s     TMP-PUSH-BACK\n", tmp->name);
	printf("%s     RUNNER-PUSH-BACK\n", runner->name);
	tmp->next = NULL;
	tmp->prev = runner;
	runner->next = tmp;
}

void	push_insert(t_arg *tmp)
{
	tmp->prev->next = tmp;
}
