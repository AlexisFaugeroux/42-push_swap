/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:40 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 20:04:02 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void	sort_three(t_stack	**stack)
{
	t_stack	*biggest;

	if (!stack || !*stack)
		return ;
	biggest = find_biggest(*stack);
	if (biggest == *stack)
		ra(stack);
	else if (biggest == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
