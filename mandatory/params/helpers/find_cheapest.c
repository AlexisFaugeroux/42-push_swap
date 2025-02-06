/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:42:04 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:06:57 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack			*cheapest;
	unsigned int	lowest;

	if (!stack || !stack)
		return (NULL);
	cheapest = stack;
	lowest = stack->cost + stack->target->cost;
	while (stack)
	{
		if (stack->cost + stack->target->cost + 1 < lowest)
		{
			cheapest = stack;
			lowest = stack->cost + stack->target->cost + 1;
		}
		stack = stack->next;
	}
	return (cheapest);
}
