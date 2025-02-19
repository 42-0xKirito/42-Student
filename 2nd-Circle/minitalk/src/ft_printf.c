/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:55:19 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/04 21:43:31 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int				print;
	unsigned long	p;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		p = (unsigned long long)va_arg(args, void *);
		if (p == 0)
			return (ft_putstr("(nil)"));
		print += ft_putstr("0x") + ft_puthex_p(p, 'x');
	}
	else if (c == 'd' || c == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		print;
	int		i;

	i = 0;
	print = 0;
	va_start(args, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			print += ft_format(s[i + 1], args);
			i++;
		}
		else
			print += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (print);
}

// int main()
// {
// 	//void *ptr = NULL;
// 	ft_printf("%u\n", 6);
// 	//printf("%p\n", ptr);
// 	//ft_printf("%d\n", i);
// }