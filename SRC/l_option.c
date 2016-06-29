/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/29 21:26:47 by asalama          ###   ########.fr       */
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

void			nb_hardlinks(t_arg *runner, t_file *file)
{
	file->nb_hlink = runner->buf->st_nlink;
}

void		get_file_owner(t_arg *runner, t_file *file)
{
	t_passwd		*passwd;

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

void		get_file_size(t_arg *runner, t_file *file)
{
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
		tmp = ft_strsub(c_time, 20, 5);
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
	nb_hardlinks(runner, file);
	get_file_owner(runner, file);
	get_file_group(runner, file);
	get_file_size(runner, file);
	get_file_time(runner,file);
	get_link(runner, file);
}
