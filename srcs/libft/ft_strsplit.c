/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/15 22:23:25 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter.
** If the allocation fails the function returns NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’) returns the array ["hello",
** "fellow", "students"].
*/

#include "libft.h"

static void		*ft_free_warr(char ***warr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free((*warr)[i++]);
	free(*warr);
	return (NULL);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	ctr;

	ctr = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++ctr;
		while (*s && *s != c)
			++s;
	}
	return (ctr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**warr;
	char	**p_warr;
	size_t	len;

	if (!s || !(warr = (char **)malloc((ft_count_words(s, c) + 1) * \
					sizeof(char *))))
		return (NULL);
	p_warr = warr;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			len = 1;
			while (s[len] != c && s[len])
				++len;
			if (!(*p_warr = ft_strsub(s, 0, len)))
				return (ft_free_warr(&warr, p_warr - warr));
			++p_warr;
			s += len;
		}
	}
	*p_warr = NULL;
	return (warr);
}
