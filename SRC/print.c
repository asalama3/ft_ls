/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:08:57 by asalama           #+#    #+#             */
/*   Updated: 2016/06/20 21:26:24 by asalama          ###   ########.fr       */
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

void		print_file(t_arg *runner)
{
	char	*tmp;

	ft_putendl(runner->path);
	if (!(tmp = ft_strdup(runner->path)))
		exit(EXIT_FAILURE);
	write (1, "\n", 1);
	ft_putstr(tmp);
	write (1, "\n", 1);
	free (tmp);
}
