/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/14 01:36:59 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr < a->next->nbr)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	arg_sorted(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i + 1] && !(ft_atoi(argv[i]) < ft_atoi(argv[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (check_args(argv, argc))
		return (write(1, "Error\n", 6), 1);
	if (argc == 2 && argv[2] == NULL)
		return (free_arg(argv), 1);
	if (!arg_sorted(argv + 1))
	{
		init(&a, argv);
		sort(&a, &b);
	}
	free_all(argv, argc, a, b);
}
