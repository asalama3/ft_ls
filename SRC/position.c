/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:41:01 by asalama           #+#    #+#             */
/*   Updated: 2016/06/06 13:11:28 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	position_front(t_arg *runner, t_arg *tmp)
{
	tmp->next = runner;
	tmp->prev = runner->prev;
	runner->prev = tmp;
}

void	position_back(t_arg *runner, t_arg *tmp)
{
	tmp->next = NULL;
	tmp->prev = runner;
	runner->next = tmp;
}

void	position_insert(t_arg *tmp)
{
	tmp->prev->next = tmp;
}
