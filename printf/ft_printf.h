/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:57:21 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/12 20:15:49 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>	
#include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_format(char c, va_list args);
char	*ft_itoa(int n, char c);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int ft_puthex(unsigned long, char c);
//int ft_putptr(void *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
long	ft_putnbr(long nb);
int	ft_puthex_p(unsigned long n, char c);

#endif