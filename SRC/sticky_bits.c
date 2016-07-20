/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sticky_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:37:25 by asalama           #+#    #+#             */
/*   Updated: 2016/07/20 16:05:45 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_sticky_bits(t_arg *runner, t_file *file)
{
	if (runner->buf->st_mode & S_ISUID)
	{
		if (file->rights[3] == 'x')
			file->rights[3] = 's';
		else
			file->rights[3] = 'S';
	}
	if (runner->buf->st_mode & S_ISGID)
	{
		if (file->rights[6] == 'x')
			file->rights[6] = 's';
		else
			file->rights[6] = 'S';
	}
	if (runner->buf->st_mode & S_ISVTX)
	{
		if (file->rights[9] == 'x')
			file->rights[9] = 't';
		else
			file->rights[9] = 'T';
	}
}
