/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:37:25 by asalama           #+#    #+#             */
/*   Updated: 2016/07/06 16:44:03 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_acl(char *filename)
{
	ssize_t			xattr;
	char			str[10];
	acl_t			acl;
	acl_entry_t		dummy;

	acl = NULL;
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	printf("%zi\n", xattr);
	// wrong xattr pour /tmp -1)
	if (xattr > 0)
		xattr = 0;
	str[1] = '\0';
	if (xattr > 0)
		str[0] = '@';
	else if (acl != NULL)
		str[0] = '+';
	else
		str[0] = ' ';
	ft_putstr(str);
//	printf("%s\n", str);
}

// when to call sticky bits?
void				get_sticky_bits(t_file *file)
{
	if (S_ISUID)
	{
		if (file->rights[3] == 'x')
			file->rights[3] = 's';
		else
			file->rights[3] = 'S';
	}
	if (S_ISGID)
	{
		if (file->rights[6] == 'x')
			file->rights[6] = 's';
		else
			file->rights[6] = 'S';
	}
	if (S_ISVTX)
	{
		if (file->rights[9] == 'x')
			file->rights[9] = 't';
		else
			file->rights[9] = 'T';
	}
}
