/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option_continue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/07/21 12:35:40 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_file_size(t_arg *runner, t_file *file)
{
	if (file->rights[0] == 'b' || file->rights[0] == 'c')
	{
		file->maj = (MAJOR(runner->buf->st_rdev) / 16);
		file->min = MINOR(runner->buf->st_rdev);
	}
	else
		file->size = runner->buf->st_size;
}

void		get_file_time(t_arg *runner, t_file *file)
{
	char		*c_time;
	time_t		c;
	char		*tmp;

	c_time = ft_strnew(13);
	c = time(NULL);
	c_time = ctime(&runner->buf->st_mtime);
	if ((runner->buf->st_mtime - c) > 15778800 ||
			(runner->buf->st_mtime - c) < -15778800)
	{
		file->time_date = ft_strsub(c_time, 4, 7);
		tmp = ft_strsub(c_time, 20, 4);
		file->time_date = ft_strjoin(file->time_date, tmp);
	}
	else
		file->time_date = ft_strsub(c_time, 4, 12);
}

void		get_link(t_arg *runner, t_file *file)
{
	int		count;
	char	buf[256];

	count = readlink(runner->path, buf, 256);
	if (count == -1)
	{
		file->file_name = ft_strdup(runner->name);
	}
	else
	{
		buf[count] = '\0';
		file->file_name = ft_strjoin(ft_strdup(runner->name), " -> ");
		file->file_name = ft_strjoin(file->file_name, buf);
	}
}

void		total(t_arg *runner, t_file *file)
{
	file->nb_blocks += runner->buf->st_blocks;
}

void		l_info(t_arg *runner, t_file *file)
{
	get_rights(runner, file);
	get_sticky_bits(runner, file);
	nb_hardlinks(runner, file);
	get_file_owner(runner, file);
	get_file_group(runner, file);
	get_file_size(runner, file);
	get_file_time(runner, file);
	get_link(runner, file);
}
