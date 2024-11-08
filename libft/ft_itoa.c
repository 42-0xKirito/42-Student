/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:46:50 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/08 14:01:20 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_putnbr_char(int n)
{
	char	*res;
	int	i;
	int	tmp;

	i = 0;
	res = malloc(4 * sizeof(char));
	while (n % 10 > 0)
	{
		tmp = n % 10;
		res[i] = tmp + 48;
		i++;
		n /= 10;
	}
	res[i] = 0;
	return (res);
}

// int main()
// {
// 	char *res = ft_putnbr_char(158);
// 	int i = 0;
// 	while(res[i])
// 		i++;
// 	while (i > 0)
// 	{
// 		printf("%c", res[i]);
// 		i--;
// 	}
// 	printf("%c", res[i]);
// 	printf("\n");
// }