/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:41:09 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/21 12:45:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’.
** Each character of the string is initialized at ’\0’. If the allocation fails
** the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(size + 1) || !(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
