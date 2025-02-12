/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 03:29:28 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	tmp_a = *a;
	cheap = set_cheapest(a, b);
	set_target_node(a, b);
	tmp_b = *b;
	if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top >= 0)
		up(a, b, cheap);
	else if (cheap->cost_to_top < 0 && cheap->target_node->cost_to_top < 0)
		down(a, b, cheap);
	else if (cheap->cost_to_top < 0 && cheap->target_node->cost_to_top >= 0)
		neg_pos(a, b, cheap);
	else if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top < 0)
		pos_neg(a, b, cheap);
	pb(a, b);
}

int	av(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

t_stack	*set_cheapest(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *current;

	//init_all(a, b);
	tmp_a = *a;
	current = tmp_a;
	while (tmp_a)
	{
		if (av(current->real_cost) > av(tmp_a->real_cost))
			current = tmp_a;
		tmp_a = tmp_a->next;
	}
	return(current);
}

void	set_real_cost(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		ac;
	int		atc;

	tmp = *a;
	while (tmp)
	{
		ac = tmp->cost_to_top;
		atc = tmp->target_node->cost_to_top;
		if (ac >= 0 && atc >= 0)
		{
			if (ac > atc)
				tmp->real_cost = ac;
			else
				tmp->real_cost = atc;
		}
		else if (ac < 0 && atc < 0)
		{
			if (ac < atc)
				tmp->real_cost = av(ac);
			else
				tmp->real_cost = av(atc);
		}
		else
			tmp->real_cost = av(ac) + av(atc);
		tmp = tmp->next;
	}
}

void	init_all(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_cost_top(*a);
	set_cost_top(*b);
	set_target_node(a, b);
	set_real_cost(a, b);
	// check_cost(a, b);
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

void max_to_top(t_stack **b)
{
	t_stack *high;
	t_stack *tmp_b;
	
	tmp_b = *b;
	high = find_high(tmp_b);
	if (high->cost_to_top > 0)
	{
		while (*b != high)
			rb(b, 0);
	}
	if (high->cost_to_top < 0)
	{
		while (*b != high)
			rrb(b, 0);
	}
}

void	final_sort(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack *tmp;

	tmp_a = *a;
	tmp_b = *b;
	tmp = ft_lstlast(*a);
	while (tmp->nbr > (*b)->nbr)
	{
		rra(a, 0);
		tmp = ft_lstlast(*a);
	}
	while (*b)
	{
		if (tmp->nbr < (*a)->nbr && tmp->nbr > (*b)->nbr)
		{
			rra(a, 0);
			tmp = ft_lstlast(*a);
		}
		else
			pa(a, b);
	}
	if ((*a)->nbr > ft_lstlast(*a)->nbr)
		rra(a, 0);
}

void	sort_big(t_stack **a, t_stack **b)
{
	while (*a)
	{
		init_all(a, b);
		if (ft_lstlast(*a)->index <= 5)
		{
			if (!stack_sorted(*a))
				sort_five(a, b);
			max_to_top(b);
			final_sort(a, b);
			return;
		}
		cheap_to_top(a, b);
	}
	// while (*a)
	// {
	// 	init_all(a, b);
	// 	cheap_to_top(a, b);
	// }
	// max_to_top(b);
	// // sort_three(a);
	// while (*b)
	// {
	// 	pa(a, b);
	// }
}

int    check_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    int        ac;
    int        atc;
    int tmp;
	int tmpb;
    
    tmp_a = *a;
    // tmp = set_half(*a, 0);
	// tmpb = set_half(*b, 0);
	// if (ft_lstlast(*a)->index < tmpb)
	// 	return (0);
    while (tmp_a)
    {
        ac = tmp_a->cost_to_top;
        atc = tmp_a->target_node->cost_to_top;
        // if (ac < 0 && atc > 0)
        // {
        //     if ((av(ac) + atc) > tmp + (tmp - av(ac)))
        //     {
        //         tmp_a->real_cost = (ac + tmp) + (tmp - atc);
        //         tmp_a->cost_to_top = av(ac) + tmp_a->real_cost;
        //     }
        // }
        // else if (ac > 0 && atc < 0)
        // {
        //     if ((av(atc) + ac) > tmpb + (tmpb - av(atc)))
        //     {
        //         tmp_a->target_node->real_cost = (atc + tmp) + (tmp - ac);
        //         tmp_a->target_node->cost_to_top = av(atc) + tmp_a->target_node->real_cost;
        //     }
        // }
        if (ac >= 0 && atc >= 0)
        {
            if (ac > atc)
                tmp_a->target_node->real_cost = 0;
            else
                tmp_a->real_cost = 0;
        }
        else if (ac < 0 && atc < 0)
        {
            if (ac < atc)
                tmp_a->target_node->real_cost = 0;
            else
                tmp_a->real_cost = 0;
        }
        tmp_a = tmp_a->next;
    }
    return (0);
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
		sort_big(a, b);
	}
}

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
		printf("[%d] c.%d %d\n", stack_a->index, stack_a->nbr, stack_a->nbr);
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
		//set_index(a);
		//print_stacks(a, b);
	}
	// if (stack_sorted(a))
	// 	printf("ok\n");
	// else
	// 	printf("not ok\n");
}
