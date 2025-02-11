/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:44 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/11 00:25:31 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **a, char **argv)
{
	append_node(a, argv);
	set_index(*a);
	set_0(*a);
}

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