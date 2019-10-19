/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:21:24 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/21 14:50:16 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 0;
	while (*str == ' ' || (*str > 8 && *str < 13) || *str == '\r')
		++str;
	if (*str == '-')
	{
		sign = 1;
		++str;
	}
	else if (*str == '+')
		++str;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (int)*str++ - '0';
		if (result > 9223372036854775807)
			return (!sign ? -1 : 0);
	}
	return (sign ? -result : result);
}
