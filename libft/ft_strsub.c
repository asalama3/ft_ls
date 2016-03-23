/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:57:49 by asalama           #+#    #+#             */
/*   Updated: 2016/01/19 12:37:08 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	ret = ft_strnew(len);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	return (ret);
}
