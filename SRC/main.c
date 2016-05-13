/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/05/13 19:32:10 by asalama          ###   ########.fr       */
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

void		print_av_list(t_arg *lst)
{
	t_arg		*runner;

	if (lst != NULL)
	{
		runner = lst;
		ft_putendl("///////ARGV LIST //////////");
		while (runner)
		{
			ft_putendl(runner->name);
			runner = runner->next;
		}
		write(1, "\n", 1);
	}
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
	return (0);
}

void			check_flags(t_flags option)
{
	printf("flag -l: %i\n", option.l);
	printf("flag -r: %i\n", option.r);
	printf("flag -a: %i\n", option.a);
	printf("flag -t: %i\n", option.t);
	printf("flag -cap_r: %i\n", option.cap_r);
}

int			main(int argc, char **argv)
{
	t_flags		option;
	t_arg		*arg_lst;
	int			ret;

	if (!(arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg))))
		return (-1);
	if (argc >= 1)
	{
		if ((ret = flags(argv, &option)) == -1)
			return (-1);
		check_flags(option);
//		if (ft_ls(argv + ret, option) == -1)
//			return (-1);
	}
	return (0);
}
