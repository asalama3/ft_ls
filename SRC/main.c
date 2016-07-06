/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 13:01:49 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags		option;
	int			ret;

	ret = 0;
	if ((ret = flags(argv, &option)) == -1)
		return (-1);
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
