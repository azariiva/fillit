/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/15 22:36:16 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l_needle;

	if (!(l_needle = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack && len-- >= l_needle)
	{
		if (ft_strnequ(needle, haystack, l_needle))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
