/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 03:10:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
    int             nbr;
	int				index;
	int				cost_to_top;
	int				real_cost;
	struct s_stack	*target_node;
    struct s_stack  *next;
}   t_stack;

// Commands
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rra(t_stack **a, int x);
void	rrb(t_stack **b, int x);
void	sa(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Utils
t_stack	*find_high(t_stack *a);
t_stack *find_min(t_stack *a);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);

// Check / Parsing
int		check_args(char **argv);
int		check_flow(char **argv);
int		check_repetition(char **argv);
int		stack_sorted(t_stack *a);

// Init
void	init(t_stack **a, char **argv);
void	set_cost_top(t_stack *a);
void	append_node(t_stack **a, char **argv);
void	set_index(t_stack *stack);
void	set_0(t_stack *stack);
void	set_target_node(t_stack **a, t_stack **b);
t_stack	*set_cheapest(t_stack **a, t_stack **b);
int		check_cost(t_stack **a, t_stack **b);
void	init_all(t_stack **a, t_stack **b);


// Sorting
void	sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);



void    print_stacks(t_stack *stack_a, t_stack *stack_b);
#endif