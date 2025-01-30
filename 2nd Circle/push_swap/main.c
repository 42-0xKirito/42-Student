/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/30 18:15:29 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Set index for each node

void	set_index(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

// fill a->nbr then a->next->nbr ...

void	append_node(t_stack **a, char **argv)
{
	int			i;
	t_stack		*current;
	t_stack		*new_node;

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

// Find highest number in stack

t_stack *find_high(t_stack *a)
{
    t_stack *high;
	
	high = a;
    if (!a)
        return NULL;
    while (a)
    {
        if (a->nbr > high->nbr)
            high = a;
        a = a->next;
    }
    return (high);
}

// Sorting three arg

void	sort_three(t_stack **a)
{
	t_stack	*high;

	high = find_high(*a);
	if (high->index == 1)
	{
		ra(a);
		set_index(*a);
	}
	if (high->index == 2)
	{
		rra(a);
		set_index(*a);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sa(a);
		set_index(*a);
	}
	return ;
}

// Will aplly sorting for 2, 3, 4 & 5 arg
// And then if more algo

void sort(t_stack **a, t_stack **b)
{
	if (ft_lstlast(*a)->index == 2)
		sa(a);
	else if (ft_lstlast(*a)->index == 3)
		sort_three(a);
	else if (ft_lstlast(*a)->index <= 5)
	{
		//pb(a, b);
		if (ft_lstlast(*a)->index == 4)
			//pb(a, b);
		sort_three(a);
	}
	return ;
}

// Check if sorted | return 1 if sorted

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

// int	check_repetition(t_stack **a)
// {
// 	return (1);
// }

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
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	append_node(&a, argv);
	set_index(a);
	printf("%d\n%d\n%d\n\n", a->nbr, a->next->nbr, a->next->next->nbr);
	if (!stack_sorted(a))
	{
		sort(&a, &b);
		printf("%d\n%d\n%d\n\n", a->nbr, a->next->nbr, a->next->next->nbr);
	}
	if (stack_sorted(a))
		printf("ok\n");
	else
		printf("not ok\n");
}
