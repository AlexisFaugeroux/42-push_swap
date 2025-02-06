/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:39 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:11:42 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_matrix
{
	char	**data;
	size_t	size;
}				t_matrix;

typedef struct s_stack
{
	int				value;
	unsigned int	position;
	unsigned int	cost;
	bool			is_up_median;
	bool			is_max_val;
	size_t			size;
	struct s_stack	*target;
	struct s_stack	*next;
}				t_stack;

// algos
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	rotation(t_stack **cheapest, t_stack **stack_a, t_stack **stack_b);
void	reverse_rotation(t_stack **cheapest,
			t_stack **stack_a, t_stack **stack_b);
void	mix_rotation(t_stack **cheapest, t_stack **stack_a, t_stack **stack_b);

// instructions
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// params
int		find_median(t_stack *stack);
int		find_max_val(t_stack *stack);
t_stack	*find_target(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);
void	set_size(t_stack *stack);
void	set_position(t_stack *stack);
void	set_is_max_val(t_stack *stack);
void	set_target(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack_a);
void	update_params(t_stack *stack_a, t_stack	*stack_b);

// parse
void	parse(int argc, char **argv, t_matrix *matrix);
bool	every(char **data, size_t size, bool (*f)(char *));
bool	is_sort(char **data, size_t	size,
			int (*cmp)(char const *, char const *));
void	foreach(char **data, size_t	size, void (*f)(char *));
char	**join_args(char **argv);

// stack
void	init_stack(t_stack **stack_a, t_matrix *matrix);
int		stack_size(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_elem);
void	stack_clear(t_stack **stack);
void	stack_sort(t_stack **stack, int (*cmp)(int, int));
t_stack	*stack_new(int value);
t_stack	*stack_at(t_stack *stack, unsigned int nb);
t_stack	*stack_find(t_stack *stack, unsigned int search,
			bool (*cmp)(int, int));
t_stack	*stack_last(t_stack *stack);

// utils
void	free_matrix(t_matrix *matrix, size_t index);
void	matrix_error(t_matrix *matrix);

#endif
