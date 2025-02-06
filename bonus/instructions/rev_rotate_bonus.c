/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:13:25 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/06 14:38:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*new_head;

	if (!stack || !*stack || (*stack)->size <= 1)
		return ;
	new_head = stack_last(*stack);
	stack_at(*stack, (*stack)->size - 2)->next = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

void	rra_checker(t_stack **stack)
{
	rev_rotate(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	rrb_checker(t_stack **stack)
{
	rev_rotate(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	rrr_checker(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
}
