/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/13 17:59:09 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost_to_top;
	int				real_cost;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

//	cheap.c
t_stack	*set_cheapest(t_stack **a);
void	cheap_to_top(t_stack **a, t_stack **b);

//	move.c
void	up(t_stack **a, t_stack **b, t_stack *cheap);
void	down(t_stack **a, t_stack **b, t_stack *cheap);
void	neg_pos(t_stack **a, t_stack **b, t_stack *cheap);
void	pos_neg(t_stack **a, t_stack **b, t_stack *cheap);

//	real_cost.c
void	real_cost_pos(int ac, int atc, t_stack *tmp);
void	real_cost_neg(int ac, int atc, t_stack *tmp);
void	set_real_cost(t_stack **a);

// reverse_rotate.c
void	rra(t_stack **a, int x);
void	rrb(t_stack **b, int x);
void	rrr(t_stack **a, t_stack **b);

//	rotate.c
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b);

// swap_and_push.c
void	sa(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

// init.c
void	init(t_stack **a, char **argv);
void	init_all(t_stack **a, t_stack **b);
void	append_node(t_stack **a, char **argv);

//	set.c
t_stack	*set_fs(t_stack *a);
int		set_half(t_stack *a, int half);
void	set_index(t_stack *stack);
void	set_cost_top(t_stack *a);

// target_node.c
void	set_target_node(t_stack **a, t_stack **b);
void	target_plus(t_stack *tmp_a, t_stack *tmp_b, t_stack *b);

//	parse.c
int		check_args(char **argv, int argc);
int		check_flow(char **argv);
int		check_digit(char **argv);
int		check_repetition(char **argv);

//	sort_tiny.c
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//	sort.c
void	sort(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);
void	final_sort(t_stack **a, t_stack **b);

//	ft_split.c
char	**ft_split(char const *s, char c);

//	utils.c
t_stack	*find_min(t_stack *a);
t_stack	*find_high(t_stack *a);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
long	ft_atoi(const char *nptr);

//	utils2.c
int		av(int i);
void	max_to_top(t_stack **b);
void	min_on_top(t_stack **a, t_stack *min);

//	main.c
int		stack_sorted(t_stack *a);
int		arg_sorted(char **argv);
int		main(int argc, char **argv);

//	free.c
void	free_arg(char **argv);
void	free_all(char **argv, int argc, t_stack *a, t_stack *b);
void	ft_lstclear(t_stack **lst);

#endif