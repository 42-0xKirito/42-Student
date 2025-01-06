/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:57:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/06 01:54:09 by engiacom         ###   ########.fr       */
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
int		ft_atoi(const char *nptr);

#endif