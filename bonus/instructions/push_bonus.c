/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:12:59 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:01:03 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*top_src;

	if (!src || !*src || (*src)->size == 0)
		return ;
	top_src = pop(src);
	if (!top_src)
		return ;
	if (!*dest)
		stack_add_back(dest, top_src);
	else
	{
		top_src->next = *dest;
		*dest = top_src;
	}
}

void	pa_checker(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	update_params(*stack_a, *stack_b);
}

void	pb_checker(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	update_params(*stack_a, *stack_b);
}
