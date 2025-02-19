/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:26:07 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/08 16:48:20 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_test_strlcat()
{
	char *src = " World!";
	char dest[13] = "Hello";
	printf("\nft_strlcat\n\n");
	printf("Test [Hello] [ World!] [13] | Expected [12] [Hello World!] : Result [%zu] [%s]\n", ft_strlcat(dest, src, sizeof(dest)), dest);
}

void	ft_test_toupper()
{
	printf("\nft_toupper\n\n");
	printf("Test [a] [z] [7] [A] [;] | Expected [A] [Z] [7] [A] [;] : Result [%c] [%c] [%c] [%c] [%c]\n", ft_toupper('a'), ft_toupper('z'), ft_toupper('7'), ft_toupper('A'), ft_toupper(';'));
}

void	ft_test_tolower()
{
	printf("\nft_toupper\n\n");
	printf("Test [A] [Z] [7] [a] [;] | Expected [a] [z] [7] [a] [;] : Result [%c] [%c] [%c] [%c] [%c]\n", ft_tolower('A'), ft_tolower('Z'), ft_tolower('7'), ft_tolower('a'), ft_tolower(';'));
}

void	ft_test_strchr()
{
	printf("\nft_strchr\n\n");
	printf("Test [Hello World!] [87] | Expected [World!] : Result [%s]\n", ft_strchr("Hello World!", 87));
	printf("Test [Hello World!] [15] | Expected [(null)] : Result [%s]\n", ft_strchr("Hello World!", 15));
}

void	ft_test_strrchr()
{
	printf("\nft_strrchr\n\n");
	printf("Test [ABC 123 ABC 456] [65] | Expected [ABC 456] : Result [%s]\n", ft_strrchr("ABC 123 ABC 456", 65));
	printf("Test [Hello World!] [15] | Expected [(null)] : Result [%s]\n", ft_strrchr("Hello World!", 15));
}

void	ft_test_strncmp()
{
	printf("\nft_strncmp\n\n");
	printf("Test [Hello World!] [Hello Moon!] [5] | Expected [0] : Result [%d]\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("Test [Hello World!] [Hello Moon!] [7] | Expected [10] : Result [%d]\n", ft_strncmp("Hello World!", "Hello Moon!", 7));
}

void	ft_test_memchr()
{
	printf("\nft_memchr\n\n");
	printf("Test [Hello World!] [87] [12] | Expected [World!] : Result [%s]\n", (char *)ft_memchr("Hello World!", 87, 12));
	printf("Test [Hello World!] [15] [12] | Expected [(null)] : Result [%s]\n", (char *)ft_memchr("Hello World!", 15, 12));
}

void	ft_test_memcmp()
{
	printf("\nft_memcmp\n\n");
	printf("Test [Hello World!] [Hello Moon!] [7] | Expected [10] : Result [%d]\n", ft_memcmp("Hello World!", "Hello Moon!", 7));
	printf("Test [Hello World!] [Hello Moon!] [5] | Expected [0] : Result [%d]\n", ft_memcmp("Hello World!", "Hello Moon!", 5));
}

void	ft_test_strnstr()
{
	printf("\nft_strnstr\n\n");
	printf("Test [Hello World!] [World] [12] | Expected [World!] : Result [%s]\n", ft_strnstr("Hello World!", "World", 12));
	printf("Test [Hello World!] [World] [5] | Expected [(null)] : Result [%s]\n", ft_strnstr("Hello World!", "World", 5));
	printf("Test [Hello World!] [] [12] | Expected [Hello World!] : Result [%s]\n", ft_strnstr("Hello World!", "", 12));
}

void	ft_test_atoi()
{
	printf("\nft_atoi\n\n");
	printf("Test [-12345ABC;154] | Expected [-12345] : Result [%d]\n", ft_atoi("-12345ABC;154"));
	printf("Test [  -+--12345ABC;154] | Expected [0] : Result [%d]\n", ft_atoi("  -+--12345ABC;154"));
}

// void	ft_test_calloc()
// {
// 	char	*str = "fjbflqjbfklqjflkqbkl";
// 	char	str1[20];
	
// 	//str1 = (char *)malloc(80);
// 	str = (char *)ft_calloc(0,0);
	
// 	printf("\nft_calloc\n\n");
// 	printf("%s\n", str);
// 	printf("%s\n", str1 );
// }

void	ft_test_strdup()
{
	printf("\nft_strdup\n\n");
	printf("Test [Hello World!] | Expected [Hello World!] : Result [%s]\n", ft_strdup("Hello World!"));
}

void	ft_test_substr()
{
	printf("\nft_substr\n\n");
	printf("Test [Hello World!] [6] [6] | Expected [World!] : Result [%s]\n", ft_substr("Hello World!", 6, 0));
}

void	ft_test_strjoin()
{
	printf("\nft_strjoin\n\n");
	printf("%s\n", ft_strjoin("Hello ", "World!"));
}

void	ft_test_strtrim()
{
	printf("\nft_strtrim\n\n");
	printf("Test [.*.*.Hello.*.World!.*.*.] [.*] | Expected [Hello.*.World!] : Result [%s]\n", ft_strtrim((".*.*.Hello.*.World!.*.*."), ".*"));
}

void	ft_test_split()
{
	printf("\nft_split\n\n");
	printf("Test [..Hello...World...!..] [.]\nExpected tab[0] [Hello] tab[1] [World] tab[2] [!] tab[3] [(null)]\nResult : ");
	char **tab = ft_split("..Hello...World...!..", '.');
	int i = 0;
	while (tab[i] != NULL)
	{
		printf("tab[%d] [%s] ",i, tab[i]);
		i++;
	}
	printf("tab[%d] [%s]\n", i, tab[i]);
}

void	ft_test_itoa()
{
	printf("\nft_itoa\n\n");
	printf("%s\n", ft_itoa(1254));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}

void	ft_test_strmapi()
{
	printf("\nft_strmapi\n\n");
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
	ft_test_strlcat();
	ft_test_toupper();
	ft_test_tolower();
	ft_test_strchr();
	ft_test_strrchr();
	ft_test_strncmp();
	ft_test_memchr();
	ft_test_memcmp();
	ft_test_strnstr();
	ft_test_atoi();
	// ft_test_calloc();
	ft_test_strdup();
	ft_test_substr();
	ft_test_strjoin();
	ft_test_strtrim();
	ft_test_split();
	ft_test_itoa();
	//ft_test_strmapi();
}