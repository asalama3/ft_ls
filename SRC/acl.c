/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:37:25 by asalama           #+#    #+#             */
/*   Updated: 2016/07/08 16:00:18 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_sticky_bits(t_file *file)
{
	if (S_ISUID & S_IXUSR)
	{
		if (file->rights[3] == 'x')
			file->rights[3] = 's';
		else
			file->rights[3] = 'S';
	}
	if (S_ISGID & S_IXGRP)
	{
		if (file->rights[6] == 'x')
			file->rights[6] = 's';
		else
			file->rights[6] = 'S';
	}
	if (S_ISVTX & S_IXOTH)
	{
		if (file->rights[9] == 'x')
			file->rights[9] = 't';
		else
			file->rights[9] = 'T';
	}
}
