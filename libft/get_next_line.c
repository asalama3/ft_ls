/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:43:34 by asalama           #+#    #+#             */
/*   Updated: 2016/01/29 17:18:28 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		add_link(t_link **list, int fd)
{
	t_link	*link;
	t_link	*runner;

	if ((link = (t_link*)ft_memalloc(sizeof(t_link))))
	{
		link->fd = fd;
		link->mem = ft_strnew(BUFF_SIZE);
		link->next = NULL;
		if (*list)
		{
			runner = *list;
			while (runner->next)
				runner = runner->next;
			runner->next = link;
			link->prev = runner;
		}
		else
		{
			link->prev = NULL;
			*list = link;
		}
		return (1);
	}
	return (0);
}

static int		destroy_link(t_link **list, int fd)
{
	t_link	*runner;

	runner = *list;
	while (runner)
	{
		if (runner->fd == fd)
		{
			if (runner->prev)
				runner->prev->next = runner->next;
			else
				*list = runner->next;
			if (runner->next)
				runner->next->prev = runner->prev;
			free(runner->mem);
			free(runner);
			return (0);
		}
		runner = runner->next;
	}
	return (0);
}

t_link			*search_fd(t_link **list, int fd)
{
	t_link		*runner;

	if (!*list)
	{
		add_link(list, fd);
		runner = *list;
	}
	else
	{
		runner = *list;
		while (runner && runner->fd != fd)
			runner = runner->next;
		if (!runner)
		{
			add_link(list, fd);
			runner = *list;
			while (runner->next)
				runner = runner->next;
		}
	}
	return (runner);
}

int				cut(t_link *runner, char **line, char *buff, int ret)
{
	while (runner->mem[ret] && runner->mem[ret] != '\n')
		ret++;
	*line = ft_strncpy(ft_strnew(ret), runner->mem, ret);
	if (runner->mem[ret] == '\n')
		ret++;
	free(buff);
	buff = ft_strncpy(ft_strnew(ft_strlen(runner->mem) - ret),
			&runner->mem[ret], ft_strlen(runner->mem) - ret);
	free(runner->mem);
	runner->mem = buff;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buff;
	static t_link	**list = NULL;
	t_link			*runner;
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!list && !(list = (t_link**)ft_memalloc(sizeof(t_link*))))
		return (-1);
	runner = search_fd(list, fd);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!ft_strchr(runner->mem, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
	{
		tmp = ft_strjoin(runner->mem, buff);
		if (!tmp || ret == -1)
			return (-1);
		free(runner->mem);
		runner->mem = tmp;
		ft_bzero(buff, BUFF_SIZE);
	}
	if (runner->mem[0] == '\0')
		return (destroy_link(list, fd));
	return (cut(runner, line, buff, 0));
}
