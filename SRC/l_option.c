/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:09:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/22 19:15:40 by asalama          ###   ########.fr       */
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
	return (len);
}
/*
void		get_file_owner(t_arg *runner)
{
}
*/
void		get_file_group(t_arg *runner)
{
	t_group		*group;

	group = getgrgid(runner->buf->st_gid);
	printf("%s", group->gr_name);
}

void		get_file_size()
{
}

void		print_rights(char *rights, int len)
{
	ft_putstr(rights);
	ft_putstr("\n");
	ft_putnbr(len);
	ft_putstr("\n");
}
