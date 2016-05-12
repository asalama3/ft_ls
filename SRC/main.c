/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:53:19 by asalama           #+#    #+#             */
/*   Updated: 2016/05/12 22:09:37 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"


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

void		print_av_list(t_arg **lst)
{
	t_arg		*runner;

	if (*lst)
	{
		runner = *lst;
		ft_putendl("///////ARGV LIST //////////");
		while (runner)
		{
			printf("%s\n", (runner->name));
			runner = runner->next;
		}
		write(1, "\n", 1);
	}
}

int			flags(char **argv, t_flags *option, t_arg *arg_lst)
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
		{
			get_av_list(&argv[i], option);
		}
		i++;
	}
//	if (!list_len(argv[i]))
//		get_av_list("./", &option);
	print_av_list(&arg_lst);
	return (0);
}
int			main(int argc, char **argv)
{
	t_flags		option;
//	int			k;
	t_arg		arg_lst;

//	k = 1;
//	if ((k = flags_options(argv, &option)) == -1)
//		return (-1);
//	else if (k == argc)
//		argv[--k] = ".";
	if (argc >= 1)
	{
		if (flags(argv, &option, &arg_lst) == -1)
			return (-1);
	}
//	ls(&in, argc, argv, k);
	return (0);
}
