/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:46:47 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:06:41 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	update_params(*stack_a, *stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	update_params(*stack_a, *stack_b);
	ft_putstr_fd("pb\n", 1);
}
