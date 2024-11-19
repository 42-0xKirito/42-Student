/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:57:21 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/14 20:29:34 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>	
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_format(char c, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_puthex(unsigned long n, char c);
size_t	ft_strlen(const char *s);
long	ft_putnbr(long nb);
int		ft_puthex_p(unsigned long n, char c);

#endif