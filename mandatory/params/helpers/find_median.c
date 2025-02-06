/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:12:34 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 17:42:00 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	cpm_int(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	else
		return (0);
}

int	find_median(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*new_node;
	t_stack	*curr;
	int		median;

	if (!stack)
		return (0);
	tmp_stack = stack_new((int)stack->value);
	tmp_stack->size = stack->size;
	curr = stack->next;
	while (curr)
	{
		new_node = stack_new((int)curr->value);
		if (!new_node)
			exit(EXIT_FAILURE);
		stack_add_back(&tmp_stack, new_node);
		curr = curr->next;
	}
	stack_sort(&tmp_stack, cpm_int);
	median = stack_at(tmp_stack, stack->size / 2)->value;
	stack_clear(&tmp_stack);
	return (median);
}
