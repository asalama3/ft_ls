/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:48:20 by asalama           #+#    #+#             */
/*   Updated: 2016/06/28 19:33:04 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_options(char c, t_flags *option)
{
	if (c == 'R')
		option->cap_r = 1;
	else if (c == 'r')
		option->r = 1;
	else if (c == 'a')
		option->a = 1;
	else if (c == 't')
		option->t = 1;
	else if (c == 'l')
		option->l = 1;
	else
		ft_error(c);
	return (0);
}

int			flags(char **argv, t_flags *option)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1])
		{
			j = 1;
			while (argv[i][j])
			{
				if (get_options(argv[i][j], option) == -1)
					return (-1);
				j++;
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

void			check_flags(t_flags option)
{
	printf("flag -l: %i\n", option.l);
	printf("flag -r: %i\n", option.r);
	printf("flag -a: %i\n", option.a);
	printf("flag -t: %i\n", option.t);
	printf("flag -cap_r: %i\n", option.cap_r);
}
