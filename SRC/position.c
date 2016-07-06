/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:41:01 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 16:03:33 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	position_front(t_arg *runner, t_arg *tmp)
{
	tmp->next = runner;
	tmp->prev = runner->prev;
	runner->prev = tmp;
}

int		position_back(t_arg *runner, t_arg *tmp)
{
	tmp->next = NULL;
	tmp->prev = runner;
	runner->next = tmp;
	return (1);
}

void	position_insert(t_arg *tmp)
{
	tmp->prev->next = tmp;
}
