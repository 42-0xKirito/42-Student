/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:22 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/12 19:23:16 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_nb(int i)
{
	i += '0';
	write(1, &i, 1);
}

long	ft_len(long n)
{
	long	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len = len * 10;
	}
	return (len);
}

long	ft_putnbr(long nb)
{
	long	len;
	long	i;

	len = ft_len(nb);
	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		i++;
	}
	while (len != 0)
	{
		ft_putchar_nb(nb / len);
		nb = nb % len;
		len = len / 10;
		i++;
	}
	return (i);
}
