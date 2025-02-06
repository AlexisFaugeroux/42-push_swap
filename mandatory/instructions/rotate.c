/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:11:40 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/24 17:10:29 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ra(t_stack **stack)
{
	rotate(stack);
	set_position(*stack);
	set_cost(*stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	set_position(*stack);
	set_cost(*stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
	ft_putstr_fd("rr\n", 1);
}
