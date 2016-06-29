/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/29 22:55:33 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags		option;
	int			ret = 0;

	if ((ret = flags(argv, &option)) == -1)
		return (-1);
//	check_flags(option);
	if (argc - ret > 0)
	{
		if (ft_ls(argv + ret, option) == -1)
			return (-1);
//	printf("%iret\n", ret);
	}
	else if (argc == 1 || (argc - ret) == 0)
	{
		argv[ret] = ft_strdup(".");
		argv[ret + 1] = NULL;
		ft_ls(argv + ret, option);
		free (argv[ret]);
	}
//	printf("%iargc\n", argc);
//	printf("%iret\n", ret);
//	printf("%s------------------\n", argv[0]);
//	printf("%s------------------\n", argv[1]);
//	printf("%s------------------\n", argv[2]);
	return (0);
}
