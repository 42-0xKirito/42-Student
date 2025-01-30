/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/29 17:31:17 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 0;
	res = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			res *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * res);
}

void	append_node(t_stack **a, char **argv)
{
	int		i;
	t_stack	*current;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (!new_node)
			return ;
		if (*a == NULL)
			*a = new_node;
		else
		{
			current = *a;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
		i++;
	}
}

t_stack	*find_high(t_stack *a)
{
	t_stack *high;

	high = a;
	while (a)
	{
		if (a->nbr > high->nbr)
		{
			high = a;
		}
		a = a->next;
	}
	return (high);
}

void	sort_three(t_stack **a)
{
	t_stack	*high;

	high = find_high(*a);
	
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	append_node(&a, argv);
	sort_three(&a);
}
