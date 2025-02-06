/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:58:54 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 19:15:50 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	int_error(t_matrix *matrix, t_stack **stack_a)
{
	stack_clear(stack_a);
	matrix_error(matrix);
}

static void	alloc_error(t_matrix *matrix, size_t index, t_stack **stack_a)
{
	free_matrix(matrix, index);
	stack_clear(stack_a);
	exit(EXIT_FAILURE);
}

static void	find_dup(t_matrix *matrix, t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *stack_a;
	while (curr && curr->next)
	{
		tmp = curr;
		while (tmp && tmp->next)
		{
			if (curr->value == curr->next->value)
			{
				stack_clear(stack_a);
				matrix_error(matrix);
			}
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

void	init_stack(t_stack **stack_a, t_matrix *matrix)
{
	size_t	i;
	long	nb;
	t_stack	*new_node;

	if (!matrix)
		return ((void)0);
	i = 0;
	while (i < matrix->size)
	{
		nb = ft_atol(matrix->data[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			int_error(matrix, stack_a);
		new_node = stack_new((int)nb);
		if (!new_node)
			alloc_error(matrix, i, stack_a);
		stack_add_back(stack_a, new_node);
		i++;
	}
	find_dup(matrix, stack_a);
	update_params(*stack_a, NULL);
	set_is_max_val(*stack_a);
	free_matrix(matrix, matrix->size);
}
