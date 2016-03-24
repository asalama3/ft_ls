/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/03/23 18:50:25 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	int				i;
	char			*tmp;
	char			*dir;
	struct dirent	*ptr;

	tmp = "./";
	i = 1;
	while (argc)
	{
		if (argc == 1)
			dir = tmp;
		else
			dir = argv[i];
		if (!(tmp = opendir(argv[i])))
			return (-1);
		while ((ptr = readdir(tmp)))
		{
			//appeler fonctions: flags
		}
		i++;
	}
	return (0);
}
