/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:38:06 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 15:07:09 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		error_exit(char *str, int error)
{
	perror(str);
	exit(error);
}

void		ft_stat_error(char *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" :", 2);
	ft_putendl_fd(strerror(errno), 2);
}

void		ft_error(char option)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-arltR] [file ...]", 2);
	exit(EXIT_FAILURE);
}
