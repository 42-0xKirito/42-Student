/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:33:40 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/05 20:47:58 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char **argv)
{
	int i;
	int k;

	i = 0;
	while (argv[i])
	{
		k = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			k++;
		while (argv[i][k] != 0)
		{
			if (argv[i][k] >= '0' && argv[i][k] <= '9')
				k++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

// check doublon

int	check_repetition(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Check Under/Overflow

int check_flow(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **argv)
{
	if (!check_digit(argv + 1))
		return (1);
	if (!check_flow(argv + 1))
		return (1);
	if (!check_repetition(argv + 1))
		return (1);
	return (0);
}