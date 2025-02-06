/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:28:28 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/24 17:09:31 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sa(t_stack **stack)
{
	swap(stack);
	set_position(*stack);
	set_cost(*stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack)
{
	swap(stack);
	set_position(*stack);
	set_cost(*stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
	set_cost(*stack_a);
	set_cost(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
