/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/24 19:54:04 by asalama          ###   ########.fr       */
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
//	char	*rights;

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
//	return (file->rights);
}

void			nb_hardlinks(t_arg *runner, t_file *file)
{
//	int		len;

	file->nb_hlink = runner->buf->st_nlink;
//	printf("%i\n", len);
//	return (len);
}

void		get_file_owner(t_arg *runner, t_file *file)
{
	t_passwd		*passwd;

	passwd = getpwuid(runner->buf->st_uid);
	printf("%s\n", passwd->pw_name);
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
//	printf("%s\n", group->gr_name);
}

void		get_file_size(t_arg *runner, t_file *file)
{
	file->size = runner->buf->st_size;
	
//	printf("%i\n", file->size);
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
//	printf("%s\n", file->time_date);
}

void		get_link(t_arg *runner, t_file *file)
{
	int		count;
	char	buf[256];
	
	count = readlink(runner->path, buf, 256);
//	printf("%i\n", count);
	if (count == -1)
	{
		file->file_name = ft_strdup(runner->name);
//		perror("error malloc");
	}
	else
	{
		file->file_name = ft_strjoin(ft_strdup(runner->name), " -> ");
		file->file_name = ft_strjoin(file->file_name, buf);
	}
//	printf("%s\n", file->file_name);
}

void		get_file_name(t_arg *runner, t_file *file)
{
	file->file_name = ft_strdup(runner->name);
//	printf("%s\n", file->file_name);
}
/*
void		print_rights(char *rights, int len)
{

	ft_putstr(rights);
	ft_putstr("\n");
	ft_putnbr(len);
	ft_putstr("\n");
}*/

void		print_l_info(t_file *file)
{
	ft_putstr(file->rights);
	ft_putstr(" ");
	ft_putnbr(file->nb_hlink);
	ft_putstr(" ");
	ft_putstr(file->pw_name);
	ft_putstr(" ");
	ft_putstr(file->gr_name);
	ft_putstr(" ");
	ft_putnbr(file->size);
	ft_putstr(" ");
	ft_putstr(file->time_date);
	ft_putstr(" ");
	ft_putstr(file->file_name);
	ft_putstr("\n");
}
