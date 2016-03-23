/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:07:28 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 12:20:12 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*mem;

	mem = NULL;
	if (!ptr)
		mem = malloc(size);
	else if (size == 0)
		free(ptr);
	else
	{
		if (mem == malloc(size))
		{
			ft_memcpy(mem, ptr, size);
			free(ptr);
		}
	}
	return (mem);
}
