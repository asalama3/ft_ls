/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 12:51:51 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		get_file_type(t_arg *runner)
{
	char	type;

	if (S_ISREG(runner->buf->st_mode) == 1)
		type = '-';
	else if (S_ISDIR(runner->buf->st_mode) == 1)
		type = 'd';
	else if (S_ISCHR(runner->buf->st_mode) == 1)
		type = 'c';
	else if (S_ISBLK(runner->buf->st_mode) == 1)
		type = 'b';
	else if (S_ISFIFO(runner->buf->st_mode) == 1)
		type = 'p';
	else if (S_ISLNK(runner->buf->st_mode) == 1)
		type = 'l';
	else
		type = 's';
	return (type);
}

void		get_rights(t_arg *runner, t_file *file)
{
	file->rights = ft_strnew(10);
	file->rights[0] = get_file_type(runner);
	file->rights[1] = (runner->buf->st_mode & S_IRUSR) ? 'r' : '-';
	file->rights[2] = (runner->buf->st_mode & S_IWUSR) ? 'w' : '-';
	file->rights[3] = (runner->buf->st_mode & S_IXUSR) ? 'x' : '-';
	file->rights[4] = (runner->buf->st_mode & S_IRGRP) ? 'r' : '-';
	file->rights[5] = (runner->buf->st_mode & S_IWGRP) ? 'w' : '-';
	file->rights[6] = (runner->buf->st_mode & S_IXGRP) ? 'x' : '-';
	file->rights[7] = (runner->buf->st_mode & S_IROTH) ? 'r' : '-';
	file->rights[8] = (runner->buf->st_mode & S_IWOTH) ? 'w' : '-';
	file->rights[9] = (runner->buf->st_mode & S_IXOTH) ? 'x' : '-';
}

void		nb_hardlinks(t_arg *runner, t_file *file)
{
	file->nb_hlink = runner->buf->st_nlink;
}

void		get_file_owner(t_arg *runner, t_file *file)
{
	t_passwd	*passwd;

	passwd = getpwuid(runner->buf->st_uid);
	if (passwd == NULL)
		file->pw_name = ft_itoa(runner->buf->st_uid);
	else
		file->pw_name = passwd->pw_name;
}

void		get_file_group(t_arg *runner, t_file *file)
{
	t_group		*group;

	group = getgrgid(runner->buf->st_gid);
	if (group == NULL)
		file->gr_name = ft_itoa(runner->buf->st_gid);
	else
		file->gr_name = group->gr_name;
}
