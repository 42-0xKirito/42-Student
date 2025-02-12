/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:44 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 06:24:59 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init(t_stack **a, char **argv)
{
	append_node(a, argv);
	set_index(*a);
}

void	init_all(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_cost_top(*a);
	set_cost_top(*b);
	set_target_node(a, b);
	set_real_cost(a);
}

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
