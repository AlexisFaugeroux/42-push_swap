/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:14:31 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/31 22:20:27 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || (*stack)->size <= 1)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	*stack = tmp;
}

void	sa_checker(t_stack **stack)
{
	swap(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	sb_checker(t_stack **stack)
{
	swap(stack);
	set_position(*stack);
	set_cost(*stack);
}

void	ss_checker(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
}
