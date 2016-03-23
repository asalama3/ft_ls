/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:01:32 by asalama           #+#    #+#             */
/*   Updated: 2016/01/25 13:12:38 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (ret)
		{
			ft_strcpy(ret, (char*)(s1));
			ft_strcat(ret, s2);
		}
		return (ret);
	}
	return (NULL);
}
