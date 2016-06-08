/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/06/08 18:54:06 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*char		*get_path(char *dir, char *name)
{
	char	*path;

	return (path);
}
*/

void		make_dir(t_arg **old_lst, t_arg *runner)
{
	while ((runner->ptr = readdir(runner->dir)))
	{



		runner = runner->next;
	}
}

int			test_dir(t_arg **old_lst)
{
	t_arg	*runner;

	runner = *old_lst;
	while (runner != NULL && S_ISDIR(runner->buf->st_mode))
	{
		if ((runner->dir = opendir(runner->name)))
			make_dir(old_lst, runner);
		if (closedir(runner->dir) == -1)
			return (-1);
		runner = runner->next;
	}
	return (0);
}
