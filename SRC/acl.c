/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:37:25 by asalama           #+#    #+#             */
/*   Updated: 2016/06/30 20:20:14 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_acl(char *filename)
{
	ssize_t			xattr;
	char			str[10];

    xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	str[1] = '\0';
	if (xattr > 0)
		str[0] = '@';
//	else if (acl != NULL)
//		str[0] = '+';
//	else
//		str[0] = ' ';
	ft_putstr(str);
//	printf("%s\n", str);
}
