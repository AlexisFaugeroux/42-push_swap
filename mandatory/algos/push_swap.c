/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:36:13 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:06:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	median;

	median = find_median(*stack_a);
	while ((*stack_a)->size > 3)
	{
		pb(stack_a, stack_b);
		if ((*stack_b)->value >= median)
			rb(stack_b);
	}
}

static void	sort(t_stack **stack_a)
{
	t_stack	*lowest;

	lowest = find_lowest(*stack_a);
	while (lowest->is_up_median && lowest->position != 0)
		ra(stack_a);
	while (!lowest->is_up_median && lowest->position != 0)
		rra(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	if (!stack_a || !*stack_a)
		return ;
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		cheapest = find_cheapest(*stack_b);
		if (cheapest->is_up_median && cheapest->target->is_up_median)
			rotation(&cheapest, stack_a, stack_b);
		else if (!cheapest->is_up_median && !cheapest->target->is_up_median)
			reverse_rotation(&cheapest, stack_a, stack_b);
		else
			mix_rotation(&cheapest, stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	sort(stack_a);
}
