/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:14:01 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 17:31:48 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*new_head;

	if (!stack || !*stack || (*stack)->size <= 1)
		return ;
	new_head = (*stack)->next;
	stack_last(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = new_head;
}

void	ra_checker(t_stack **stack)
{
	rotate(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	rb_checker(t_stack **stack)
{
	rotate(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	rr_checker(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
}
