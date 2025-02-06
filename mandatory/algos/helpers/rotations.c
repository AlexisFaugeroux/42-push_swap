/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:49:20 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:06:17 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotation(t_stack **cheapest, t_stack **stack_a, t_stack **stack_b)
{
	while ((*cheapest)->position != 0 && (*cheapest)->target->position != 0)
		rr(stack_a, stack_b);
	while ((*cheapest)->target->position != 0)
		ra(stack_a);
	while ((*cheapest)->position != 0)
		rb(stack_b);
}

void	reverse_rotation(t_stack **cheapest,
					t_stack **stack_a, t_stack **stack_b)
{
	while ((*cheapest)->position != 0 && (*cheapest)->target->position != 0)
		rrr(stack_a, stack_b);
	while ((*cheapest)->target->position != 0)
		rra(stack_a);
	while ((*cheapest)->position != 0)
		rrb(stack_b);
}

void	mix_rotation(t_stack **cheapest, t_stack **stack_a, t_stack **stack_b)
{
	while ((*cheapest)->target->is_up_median
		&& (*cheapest)->target->position != 0)
		ra(stack_a);
	while (!((*cheapest)->target->is_up_median)
		&& (*cheapest)->target->position != 0)
		rra(stack_a);
	while ((*cheapest)->is_up_median
		&& (*cheapest)->position != 0)
		rb(stack_b);
	while (!((*cheapest)->is_up_median)
		&& (*cheapest)->position != 0)
		rrb(stack_b);
}
