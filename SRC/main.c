/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/07/21 19:28:53 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_null(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (argv[i] == NULL || !ft_strlen(argv[i]))
			return (0);
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_flags		option;
	int			ret;

	ret = 0;
	if ((ret = flags(argv, &option)) == -1)
		return (-1);
	if (!check_null(argc, argv))
	{
		ft_stat_error("fts_open");
		return (0);
	}
	if (argc - ret > 0)
	{
		if (ft_ls(argv + ret, option) == -1)
			return (-1);
	}
	else if (argc == 1 || (argc - ret) == 0)
	{
		argv[ret] = ft_strdup(".");
		argv[ret + 1] = NULL;
		ft_ls(argv + ret, option);
		free(argv[ret]);
	}
	return (0);
}
