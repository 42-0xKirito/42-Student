/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:55:19 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/12 16:45:56 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int	print;
	char *str;
	
	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_putstr("0x") + ft_puthex((unsigned long)(va_arg(args, void *)), 'x');
	else if (c == 'd' || c == 'i' || c == 'u')
	{
		str = (ft_itoa(va_arg(args, int), c));
		print += ft_putstr(str);
		if (str[0] != 0)
			free (str);
	}
	else if (c == 'x' || c == 'X')
		print += ft_puthex(va_arg(args, unsigned int), c);
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
	return (print);
}

// int main()
// {
// 	void *ptr = "NULL";
// 	int i = ft_printf("%p\n", ptr);
// 	int j = printf("%p\n", ptr);
// 	ft_printf("%d %d\n", i, j);
// }