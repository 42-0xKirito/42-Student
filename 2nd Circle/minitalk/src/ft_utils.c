/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:49:07 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/14 20:27:23 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, char c)
{
	char	res[25];
	char	*base;
	int		i;
	int		j;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n != 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	j = i;
	while (i--)
	{
		ft_putchar(res[i]);
	}
	return (j);
}

int	ft_puthex_p(unsigned long n, char c)
{
	char	res[25];
	char	*base;
	int		i;
	int		j;

	if (c == 'x')
		base = "0123456789abcdef";
	if (n == 0)
		return (0);
	i = 0;
	while (n != 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	j = i;
	while (i--)
	{
		ft_putchar(res[i]);
	}
	return (j);
}
