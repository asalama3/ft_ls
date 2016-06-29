/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:39:39 by asalama           #+#    #+#             */
/*   Updated: 2016/06/29 22:54:46 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			create_link_arg_bis(t_arg **arg_lst, t_flags *option)
{
	t_arg		*link;
	(void)option;
	if (!(link = (t_arg*)ft_memalloc(sizeof(t_arg))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if (*arg_lst == NULL)
	{
		*arg_lst = link;
		return ;
	}
//	if (option->t)
//		arg_sort_time(link, arg_lst);
//	else
		arg_sort_alpha_bis(link, arg_lst);
}

int			check_stat(t_arg *link, char *file)
{
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if ((lstat(file, link->buf)) == -1)
	{
		free(link->buf);
		link->buf = NULL;
	}
	if ((!(link->path = ft_strdup(file))) || (!(link->name = ft_strdup(file))))
	{
		if (link->path)
			free(link->path);
		free(link->buf);
		free(link);
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	return (0);
}


int		ft_ls(char **argv, t_flags option)
{
	t_arg	*arg_lst;
	t_arg	*link;

	arg_lst = NULL;
	while (*argv != NULL)
	{
		if ((link = link_malloc()) == NULL)
			return (-1);
		if (check_stat(link, *argv) == -1)
			return (-1);
		else
			create_link_arg_bis(&arg_lst, &option);
		argv++;
	}
//	sort_flags(&option, &arg_lst);
// condition pour error liste:
	error_list(&arg_lst);
	arg_sort_file_dir(&arg_lst);
	if (!option.l)
		test_file(&arg_lst);
	test_dir(&arg_lst, &option);
//	print_arg_list(arg_lst);
	return (0);
}
