/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:42:34 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/28 22:03:17 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*found;
	int		lowest;

	if (!stack)
		return (NULL);
	found = stack;
	lowest = INT_MAX;
	while (stack)
	{
		if (stack->value < lowest)
		{
			found = stack;
			lowest = stack->value;
		}
		stack = stack->next;
	}
	return (found);
}
