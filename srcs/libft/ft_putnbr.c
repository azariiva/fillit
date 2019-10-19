/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2019/09/15 20:44:39 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_help_putnbr(int nb)
{
	if (nb != 0)
	{
		ft_help_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void		ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
			ft_putchar('-');
		ft_help_putnbr(ft_abs(nb / 10));
		ft_putchar(ft_abs(nb % 10) + '0');
	}
}
