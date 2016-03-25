/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:11:26 by asalama           #+#    #+#             */
/*   Updated: 2016/03/24 17:18:34 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_stat(char **argv, struct stat *buf, int k)
{
	if (!(buf = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	if ((stat(argv[k], buf)) == -1)
//		ft_stat_error(argv[k]);
		return (-1);
//		if(S_ISREG(buf->st_mode)
			printf("%s\n", argv[k]);
	return (0);
}

int			parse(t_init *in, int argc, char **argv, int k)
{
	struct stat		*buf;
//	int		i;

//	i = k;
//	ft_putendl(argv[k]);
//	if (!(in->dir == opendir(argv[i++])))
//	in->dir = opendir(argv[i++]);
//	if (in->dir == NULL)
	while (k < argc)
	{
		if (!(in->dir = opendir(argv[k])))
		{
			if((ft_stat(argv, buf, k)) == -1)
			{
				ft_putendl("yftgf");
				ft_dir_error(argv[k]);
			}
		}
		if (in->dir)
		{
			while ((in->ptr = readdir(in->dir)))
			{
				ft_putstr(in->ptr->d_name);
				ft_putchar('\n');
			}
			if (closedir(in->dir) == -1)
				ft_dir_error(argv[k]);
		}
		k++;
	}
	return (0);
}
