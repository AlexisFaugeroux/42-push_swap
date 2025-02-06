/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:09:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/26 18:40:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*stack_find(t_stack *stack, unsigned int data, bool (*cmp)(int, int))
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (cmp(stack->value, data) == 0)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
