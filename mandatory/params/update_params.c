/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:07 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/25 18:40:43 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_params(t_stack *stack_a, t_stack	*stack_b)
{
	if (stack_a)
	{
		set_size(stack_a);
		set_position(stack_a);
		set_cost(stack_a);
		set_target(stack_a, NULL);
	}
	if (stack_b)
	{
		set_size(stack_b);
		set_position(stack_b);
		set_cost(stack_b);
		set_target(stack_a, stack_b);
	}
}
