/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 17:43:30 by asalama           #+#    #+#             */
/*   Updated: 2016/06/03 19:54:59 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//creer liste d'error 
//la liste est deja avec les erreurs; 2 types d'errors; nouvelle structure;
//imprimer la liste
//free la liste

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
		tmp->next = runner ;
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
}
