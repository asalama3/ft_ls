/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:08:57 by asalama           #+#    #+#             */
/*   Updated: 2016/06/09 17:42:34 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_arg_list(t_arg *lst)
{
	t_arg	*runner;
	
	if (lst != NULL)
	{
	runner = lst;
	ft_putendl("///////ARGV LIST //////////");
	while (runner)
	{
		ft_putendl(runner->name);
		runner = runner->next;
	}
	write(1, "\n", 1);
	}
}
