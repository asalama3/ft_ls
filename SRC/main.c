/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/06/28 13:34:19 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags		option;
	int			ret = 0;
//	int			i;

	if (argc >= 2)
	{
		if ((ret = flags(argv, &option)) == -1)
			return (-1);
		check_flags(option);
		if (ft_ls(argv + ret, option) == -1)
			return (-1);
	}
//	else if (ret == 0)
//	{
//		option.l = 0;
//		i = 1;
//		argv[i] = "./";
//		ft_ls(argv, option);
//	}
//	printf("%irrrrrrrrr\n", argc);
	printf("%iret\n", ret);
//	printf("%s------------------\n", argv[0]);
//	printf("%s------------------\n", argv[1]);
//	printf("%s------------------\n", argv[2]);
	return (0);
}
