/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/11 02:05:26 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	set_cost_to_b(t_stack *a, t_stack *b)
// {
// 	t_stack *tmp_a;
// 	t_stack *tmp_b;
// 	int		i;

// 	tmp_a = a;
// 	while (tmp_a)
// 	{
// 		i = 1;
// 		tmp_b = b;
// 		if (tmp_a->cost_to_top < 0)
// 			tmp_a->cost_to_top *= -1;
// 		if ((tmp_a->nbr > tmp_b->nbr) && tmp_b && tmp_b->next)
// 		{
// 			if (tmp_b == find_high(tmp_b))
// 				tmp_a->cost_to_b = i + tmp_a->cost_to_top;
// 			else if (tmp_a->nbr > ft_lstlast(tmp_b)->nbr)
// 			{
// 				while ((tmp_a->nbr > tmp_b->nbr) && tmp_b && tmp_b->next)
// 				{
// 					tmp_b = tmp_b->next;
// 					i++;
// 				}
// 				while ((!(tmp_a->nbr < tmp_b->next->nbr)) && tmp_b && tmp_b->next)
// 				{
// 					tmp_b = tmp_b->next;
// 					i++;
// 				}
// 				//set_cost_top(b);
// 				tmp_a->cost_to_b = i + tmp_a->cost_to_top;
// 			}
// 			else if (tmp_a->nbr < ft_lstlast(tmp_b)->nbr)
// 				tmp_a->cost_to_b = i + tmp_a->cost_to_top;
// 		}
// 		else
// 		{
// 			if (tmp_a->nbr < ft_lstlast(b)->nbr)
// 			{
// 				printf("i %d\n", tmp_a->cost_to_top);
// 				tmp_a->cost_to_b = tmp_a->cost_to_top + 1;
// 			}
// 			else
// 			{
// 				while ((tmp_a->nbr < tmp_b->nbr) && tmp_b && tmp_b->next)
// 				{
// 					tmp_b = tmp_b->next;
// 					i++;
// 				}
// 				tmp_a->cost_to_b = i + tmp_a->cost_to_top;
// 			}
// 		}
// 		if (tmp_a->next)
// 			tmp_a = tmp_a->next;
// 		else
// 			return;
// 	}
// }

void	down(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i < 0 && j < 0)
	{
		rrr(a, b);
		i++;
		j++;
	}
	while (i < 0)
	{
		rra(a, 0);
		i++;
	}
	while (j < 0)
	{
		rrb(b, 0);
		j++;
	}
}

void	up(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i > 0 && j > 0)
	{
		rr(a, b);
		i--;
		j--;
	}
	while (i > 0)
	{
		ra(a, 0);
		i--;
	}
	while (j > 0)
	{
		rb(b, 0);
		j--;
	}
}

void	neg_pos(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i < 0)
	{
		rra(a, 0);
		i++;
	}
	while (j > 0)
	{
		rb(b, 0);
		j--;
	}
}

void	pos_neg(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i > 0)
	{
		ra(a, 0);
		i--;
	}
	while (j < 0)
	{
		rrb(b, 0);
		j++;
	}
}

void	cheap_to_top(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack *cheap;

	cheap = set_cheapest(*a);
	tmp_a = *a;
	tmp_b = *b;
	if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top >= 0)
		up(a, b, cheap);
	else if (cheap->cost_to_top <= 0 && cheap->target_node->cost_to_top <= 0)
		down(a, b, cheap);
	else if (cheap->cost_to_top <= 0 && cheap->target_node->cost_to_top >= 0)
		neg_pos(a, b, cheap);
	else if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top <= 0)
		neg_pos(a, b, cheap);
	pb(a, b);
}

void	set_0(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->cheap = 0;
		tmp = tmp->next;
	}
}

int	av(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

t_stack	*set_cheapest(t_stack *a)
{
	t_stack *tmp_a;
	t_stack *current;

	tmp_a = a;
	current = tmp_a;
	while (tmp_a)
	{
		if (av(current->cost_to_top) + av(current->target_node->cost_to_top) >
				av(tmp_a->cost_to_top) + av(tmp_a->target_node->cost_to_top))
			current = tmp_a;
		tmp_a = tmp_a->next;
	}
	return(current);
}

void	init_all(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_cost_top(*a);
	set_cost_top(*b);
	set_target_node(a, b);
}

void	target_plus(t_stack *tmp_a, t_stack *tmp_b, t_stack *b)
{
	if (tmp_a->nbr > find_high(b)->nbr)
		tmp_a->target_node = find_high(b);
	else if (tmp_a->nbr < find_min(b)->nbr)
	{
		if (find_min(b) == ft_lstlast(b))
			tmp_a->target_node = tmp_b;
		else
			tmp_a->target_node = find_min(b)->next;
	}
	else
	{
		if (tmp_a->nbr > tmp_b->nbr && tmp_a->nbr < ft_lstlast(b)->nbr)
			tmp_a->target_node = tmp_b;
		else
		{
			while (!(tmp_a->nbr < tmp_b->nbr && tmp_a->nbr > tmp_b->next->nbr) && tmp_b)
				tmp_b = tmp_b->next;
			tmp_a->target_node = tmp_b->next;
		}
	}
}
void	set_target_node(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		target_plus(tmp_a, tmp_b, *b);
		tmp_a = tmp_a->next;
	}
}

t_stack *set_fs(t_stack *a)
{
	a->cost_to_top = 0;
	if (a->next)
	{
		a = a->next;
		a->cost_to_top = 1;
	}
	if (a->next)
		return (a->next);
	return (a);
}

int set_half(t_stack *a, int half)
{
	if (ft_lstlast(a)->index % 2 == 0)
		return (half = ft_lstlast(a)->index / 2);
	else
		return (half = (ft_lstlast(a)->index / 2) + 1);
}

void set_cost_top(t_stack *a)
{
	t_stack *tmp;
	int		i;
	int		half;

	tmp = a;
	half = set_half(a, 0);
	tmp = set_fs(tmp);
	i = 2;
	while (tmp && tmp->index <= half)
	{
		tmp->cost_to_top = i;
		tmp = tmp->next;
		i++;
	}
	if ((ft_lstlast(a)->index % 2) != 0)
		i--;
	while (tmp && tmp->next && tmp->index > half)
	{
		tmp->cost_to_top = -i;
		tmp = tmp->next;
		i--;
	}
	if (ft_lstlast(a)->index > 2)
		tmp->cost_to_top = -i;
}

void sort_big(t_stack **a, t_stack **b)
{
	while (*a)
	{
		init_all(a, b);
		cheap_to_top(a, b);
	}
	//max_to_top(b);
	while (*b)
		pa(a, b);
}

void sort(t_stack **a, t_stack **b)
{
	if (ft_lstlast(*a)->index == 2)
		sa(a, 0);
	else if (ft_lstlast(*a)->index == 3)
		sort_three(a);
	else if (ft_lstlast(*a)->index == 4)
		sort_four(a, b);
	else if (ft_lstlast(*a)->index == 5)
		sort_five(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
		if ((*b)->nbr < (*b)->next->nbr)
			sb(b, 0);
		//print_stacks(*a, *b);
		sort_big(a, b);
	}
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

void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("\nstack_a\t\tstack_b\n");
	printf("-------\t\t-------\n");
	while (stack_a != NULL)
	{
		printf("[%d] c.%d %d\n", stack_a->cheap, stack_a->target_node->nbr, stack_a->nbr);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("\t\t[%d] c.%d %d\n", stack_b->index, stack_b->cost_to_top, stack_b->nbr);
		stack_b = stack_b->next;
	}
	printf("\n");
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
	if (check_args(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init(&a, argv);
	if (!stack_sorted(a))
	{
		sort(&a, &b);
		print_stacks(a, b);
	}
	if (stack_sorted(a))
		printf("ok\n");
	else
		printf("not ok\n");
}
