/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/23 18:25:27 by asalama          ###   ########.fr       */
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

char		*get_rights(t_arg *runner)
{
	char	*rights;

	rights = ft_strnew(10);
	rights[0] = get_file_type(runner);
	rights[1] = (runner->buf->st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (runner->buf->st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (runner->buf->st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (runner->buf->st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (runner->buf->st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (runner->buf->st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (runner->buf->st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (runner->buf->st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (runner->buf->st_mode & S_IXOTH) ? 'x' : '-';
	return (rights);
}

int			nb_hardlinks(t_arg *runner)
{
	int		len;

	len = runner->buf->st_nlink;
//	printf("%i\n", len);
	return (len);
}

void		get_file_owner(t_arg *runner)
{
	t_passwd		*passwd;
	t_file		*file;

	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	passwd = getpwuid(runner->buf->st_uid);
	printf("%s\n", passwd->pw_name);
	if (passwd == NULL)
		file->pw_name = ft_itoa(runner->buf->st_uid);
	else
		file->pw_name = passwd->pw_name;
}

void		get_file_group(t_arg *runner)
{
	t_group		*group;
	t_file		*file;

	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	group = getgrgid(runner->buf->st_gid);
	if (group == NULL)
		file->gr_name = ft_itoa(runner->buf->st_gid);
	else
		file->gr_name = group->gr_name;
	printf("%s\n", group->gr_name);
}

void		get_file_size(t_arg *runner)
{
	t_file		*file;
	
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	file->size = runner->buf->st_size;
	
	printf("%i\n", file->size);
}

void		get_file_time(t_arg *runner)
{
	t_file		*file;
	char		*c_time;
	time_t		c;
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	c_time = ft_strnew(13);
	c = time(NULL);
//	file->time_date = runner->buf->st_mtime;
	c_time = ctime(&runner->buf->st_mtime);
//	if ((runner->buf->st_mtime - c) > 15778800 || (runner->buf->st_mtime - c) < -15778800)
	c_time = ft_strsub(c_time, 3, 7);
	printf("%s\n", c_time);
}

void		get_file_name(t_arg *runner)
{
	t_file		*file;
	
	if (!(file = (t_file*)ft_memalloc(sizeof(t_file))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	file->file_name = strdup(runner->name);
	printf("%s\n", file->file_name);

}

void		print_rights(char *rights, int len)
{
	ft_putstr(rights);
	ft_putstr("\n");
	ft_putnbr(len);
	ft_putstr("\n");
}
