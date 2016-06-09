/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:38:05 by asalama           #+#    #+#             */
/*   Updated: 2016/06/09 17:42:24 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*char		*get_path(char *dir, char *name)
{
	char	*path;

	return (path);
}
*/

int			make_dir(t_arg *dir_lst, t_arg *runner, t_flags *option)
{
	t_arg	*link;
	while ((runner->ptr = readdir(runner->dir)) != NULL)
	{
		if ((link = link_malloc()) == NULL)
			return (-1);
		if (check_stat(link, runner->ptr->d_name) == -1)
			return (-1);
		else
			create_link_arg(link, &dir_lst);
//		printf("%s  NAME:\n", runner->ptr->d_name);
	}
	sort_flags(option, &dir_lst);
	print_arg_list(dir_lst);
	return(0);
}

void			test_dir(t_arg **old_lst, t_flags *option)
{
	t_arg	*runner;
	t_arg	*dir_list;

	runner = *old_lst;
	dir_list = NULL;
	while (runner != NULL)
	{
		if (S_ISDIR(runner->buf->st_mode))
		{
			if ((runner->dir = opendir(runner->name)))
			{
				make_dir(dir_list, runner, option);
			}
			if (closedir(runner->dir) == -1)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}
		runner = runner->next;
		}
		else
			runner = runner->next;
	}
//	return (0);
}
