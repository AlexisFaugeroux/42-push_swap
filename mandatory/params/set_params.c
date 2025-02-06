/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:49:50 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:08:19 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_size(t_stack *stack)
{
	size_t	size;

	if (!stack)
		return ;
	size = stack_size(stack);
	while (stack)
	{
		stack->size = size;
		stack = stack->next;
	}
}

void	set_position(t_stack *stack)
{
	unsigned int	i;
	unsigned int	median;

	if (!stack)
		return ;
	median = stack->size / 2;
	i = 0;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->is_up_median = true;
		else
			stack->is_up_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head_a;
	t_stack	*node_b;

	if (!stack_a)
		return ;
	head_a = stack_a;
	while (stack_a)
	{
		stack_a->target = NULL;
		stack_a = stack_a->next;
	}
	node_b = stack_b;
	while (node_b)
	{
		node_b->target = find_target(head_a, node_b);
		node_b = node_b->next;
	}
}

void	set_cost(t_stack *stack)
{
	unsigned int	cost;

	if (!stack)
		return ;
	while (stack)
	{
		cost = 0;
		if (stack->position != 0)
		{
			if (stack->is_up_median)
				cost = (stack->size / 2)
					- ((stack->size / 2) - stack->position);
			else
				cost = stack->size - stack->position;
		}
		stack->cost = cost;
		stack = stack->next;
	}
}

void	set_is_max_val(t_stack *stack)
{
	int		max_val;

	if (!stack)
		return ;
	max_val = find_max_val(stack);
	while (stack)
	{
		if (stack->value == max_val)
			stack->is_max_val = true;
		else
			stack->is_max_val = false;
		stack = stack->next;
	}
}
