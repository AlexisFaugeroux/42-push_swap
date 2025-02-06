/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:11:35 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/28 22:03:17 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	int		min_val;

	if (!stack)
		return (NULL);
	min = NULL;
	min_val = INT_MAX;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_target(t_stack *stack_a, t_stack *node_b)
{
	t_stack	*target;
	t_stack	*curr;
	int		curr_max;

	if (!stack_a | !node_b)
		return (NULL);
	curr = stack_a;
	curr_max = INT_MAX;
	target = NULL;
	while (curr)
	{
		if (curr->value > node_b->value && curr->value < curr_max)
		{
			curr_max = curr->value;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		target = find_min(stack_a);
	return (target);
}
