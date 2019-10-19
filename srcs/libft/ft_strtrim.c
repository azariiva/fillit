/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:34 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/15 22:23:56 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && ISWHITESPACE(s[start]))
		++start;
	if (!s[start])
		len = 0;
	else
	{
		end = ft_strlen(s) - 1;
		while (ISWHITESPACE(s[end]))
			--end;
		len = end - start + 1;
	}
	return (ft_strsub(s, start, len));
}
