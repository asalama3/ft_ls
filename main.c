/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/03/25 19:50:17 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"


int			flags_options(char **argv, t_flags *option)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == 'R')
				option->R = 1;
			else if (argv[i][j] == 'r')
				option->r = 1;
			else if (argv[i][j] == 'a')
				option->a = 1;
			else if (argv[i][j] == 't')
				option->t = 1;
			else if (argv[i][j] == 'l')
				option->l = 1;
			else
			{
				ft_error(argv[i][j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	printf("%d\n", i);
	return (i);
}


int			main(int argc, char **argv)
{
	t_flags		option;
	t_init		in;
	int			k;

	k = 1;
	if ((k = flags_options(argv, &option)) == -1)
		return (-1);
	else if (k == argc)
		argv[--k] = ".";
	parse(&in, argc, argv, k);
	return (0);
}


/*
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
}*/
