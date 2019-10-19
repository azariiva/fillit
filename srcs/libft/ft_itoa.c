/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:41:09 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/15 20:43:28 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	int			tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp)
	{
		++len;
		tmp /= 10;
	}
	if (!(s = ft_strnew(len)))
		return (0);
	tmp = len - 2;
	s[len - 1] = ft_abs(n % 10) + '0';
	if (n < 0)
		s[0] = '-';
	n = ft_abs(n / 10);
	while (n)
	{
		s[tmp--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
