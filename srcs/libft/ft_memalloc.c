/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:47:11 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/04 17:54:30 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the alloca- tion fails, the function
** returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*b;

	if (!(b = (void *)malloc(size)))
		return (NULL);
	return (ft_memset(b, 0, size));
}
