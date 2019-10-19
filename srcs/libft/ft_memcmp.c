/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:07:24 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/11 18:12:56 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = -1;
	while (++i < n)
		if ((cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]))
			return (cmp);
	return (0);
}
