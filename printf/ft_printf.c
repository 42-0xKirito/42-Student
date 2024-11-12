/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:55:19 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/12 12:41:28 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_format(char c, va_list args)
{
	int	print;
	
	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, char));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i' || c == 'u')
		print += ft_itoa(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		print += ft_puthex(va_arg(args, int), c);
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	print;
	int	i;

	i = 0;
	print = 0;
	va_start(args, s);
	while (s[i] != NULL)
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
	return (print);
	
}