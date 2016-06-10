/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:28:18 by asalama           #+#    #+#             */
/*   Updated: 2016/06/10 16:16:09 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int			i;
	char		*tmp;
	size_t		len;

	i = 0;
	len = ft_strlen(s1) + 1;
	tmp = (char *)malloc(len * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (n && s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
		n--;
	}
	tmp[i] = '\0';
	while (n > 0)
	{
		tmp[i] = '\0';
		i++;
		n--;
	}
	return (tmp);
}
