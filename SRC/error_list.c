/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 17:43:30 by asalama           #+#    #+#             */
/*   Updated: 2016/06/05 19:50:30 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//void		print_error_list(t_err **error_lst)
//{
	//print
	//free
//}


void		sort_alpha_error_lst(t_err **error_lst)
{
	t_err	*runner;
	char	*file;
	int		error;

	runner = *error_lst;
		printf("%s SORT\n", runner->file);
	while (runner->next != NULL)
	{
		printf("%s FILE\n", runner->file);
		if (ft_strcmp(runner->file, runner->next->file) > 0)
		{
			file = runner->file;
			error = runner->error;
			runner->file = runner->next->file;
			runner->error = runner->next->error;
			runner->next->file =  file;
			runner->next->error = error;
			runner = *error_lst;
		}
		runner = runner->next;
	}
	printf("%s \n", runner->file);
}

void		error_list(char *file, t_err **error_lst, int error)
{
	t_err	*runner;
	t_err	*tmp;

	if (!(runner = (t_err*)ft_memalloc(sizeof(t_err))))
	{
		perror("error maloc");
		exit(EXIT_FAILURE);
	}
	runner->next = NULL;
	runner->prev = NULL;
	runner->file = file;
	runner->error = errno;
	if (*error_lst)
	{
		tmp = *error_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = runner;
		runner->next = NULL;
		runner->prev = runner;
	}
	else
	{
		*error_lst = runner;
		runner->prev = NULL;
		runner->next = NULL;
	}
	error = 0;
		printf("%d \n", error);
	sort_alpha_error_lst(error_lst);
//	print_arg_list(error_lst);
}
