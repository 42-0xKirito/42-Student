/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:26:07 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/06 02:48:29 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_test_isalnum()
{
	printf("\nft_isalnum\n\n");
	printf("Test [a] | Expected [1] : Result [%d]\n", ft_isalnum('a'));
	printf("Test [A] | Expected [1] : Result [%d]\n", ft_isalnum('A'));
	printf("Test [5] | Expected [1] : Result [%d]\n", ft_isalnum('5'));
	printf("Test [.] | Expected [0] : Result [%d]\n", ft_isalnum('.'));
}
void	ft_test_isalpha()
{
	printf("\nft_isalpha\n\n");
	printf("Test [a] | Expected [1] : Result [%d]\n", ft_isalpha('a'));
	printf("Test [A] | Expected [1] : Result [%d]\n", ft_isalpha('A'));
	printf("Test [5] | Expected [0] : Result [%d]\n", ft_isalpha('5'));
	printf("Test [.] | Expected [0] : Result [%d]\n", ft_isalpha('.'));
}

void	ft_test_isascii()
{
	printf("\nft_isascii\n\n");
	printf("Test [0] | Expected [1] : Result [%d]\n", ft_isascii(0));
	printf("Test [66] | Expected [1] : Result [%d]\n", ft_isascii(66));
	printf("Test [127] | Expected [1] : Result [%d]\n", ft_isascii(127));
	printf("Test [250] | Expected [0] : Result [%d]\n", ft_isascii(250));
	printf("Test [-120] | Expected [0] : Result [%d]\n", ft_isascii(-120));
}

void	ft_test_isdigit()
{
	printf("\nft_isdigit\n\n");
	printf("Test [0] | Expected [1] : Result [%d]\n", ft_isdigit('0'));
	printf("Test [9] | Expected [1] : Result [%d]\n", ft_isdigit('9'));
	printf("Test [a] | Expected [0] : Result [%d]\n", ft_isdigit('a'));
	printf("Test [.] | Expected [0] : Result [%d]\n", ft_isdigit('.'));
}

void	ft_test_isprint()
{
	printf("\nft_isprint\n\n");
	printf("Test [32] | Expected [1] : Result [%d]\n", ft_isprint(32));
	printf("Test [126] | Expected [1] : Result [%d]\n", ft_isprint(126));
	printf("Test [127] | Expected [0] : Result [%d]\n", ft_isprint(127));
	printf("Test [15] | Expected [0] : Result [%d]\n", ft_isprint(15));
}

void	ft_test_strlen()
{
	printf("\nft_strlen\n\n");
	printf("Test [Hello World!] | Expected [12] : Result [%zu]\n", ft_strlen("Hello World!"));
	printf("Test [Hello] | Expected [5] : Result [%zu]\n", ft_strlen("Hello"));
	printf("Test []] | Expected [0] : Result [%zu]\n", ft_strlen(""));
}

void	ft_test_memset()
{
	char str[] = "Hello World!";
	printf("\nft_memset\n\n");
	printf("Test [Hello World!] [.] [5] | Expected [..... World!] : Result [%s]\n", (unsigned char *)ft_memset((void *)str, '.', 5));
}

void	ft_test_bzero()
{
	char str[] = "Hello World!";
	printf("\nft_bzero\n\n");
	ft_bzero((unsigned char *)str, 5);
	printf("Test [Hello World!] [5] | Expected [] : Result [%s]\n", str);
}

void	ft_test_memcpy()
{
	char src[] = "Hello World!";
	char dest[4096];
	dest[0] = 0;
	printf("\nft_memcpy\n\n");
	ft_memcpy((void *)dest, (const void *)src, 5);
	printf("Test [] [Hello World!] [5] | Expected [Hello] : Result [%s]\n", dest);
}

void	ft_test_memmove()
{
	char src[] = "Hello World!";
	char dest[] = "World!";
	printf("\nft_memmove\n\n");
	ft_memmove((void *)dest, (const void *)src, 5);
	printf("Test [World!] [Hello World!] [5] | Expected [Hello!] : Result [%s]\n", dest);
	char dest1[] = "Hello World!";
	char *src1 = dest1;
	ft_memmove((void *)dest1+6, (const void *)src1, 5);
	printf("Test [dest+6] [src = dest] [5] | Expected [Hello Hello!] : Result [%s]\n", dest1);
	
}

void	ft_test_strlcpy()
{
	char src[] = "Hello World!";
	char dest[4096];
	printf("\nft_strlcpy\n\n");
	printf("Test [] [Hello World!] [6] | Expected [12] [Hello] : Result [%zu] [%s]\n", ft_strlcpy(dest, src, 6), dest);
}

int	main()
{
	ft_test_isalnum();
	ft_test_isalpha();
	ft_test_isascii();
	ft_test_isdigit();
	ft_test_isprint();
	ft_test_strlen();
	ft_test_memset();
	ft_test_bzero();
	ft_test_memcpy();
	ft_test_memmove();
	ft_test_strlcpy();
}