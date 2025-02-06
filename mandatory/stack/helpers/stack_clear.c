/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:26:06 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 17:07:19 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (stack)
	{
		curr = *stack;
		while (curr)
		{
			next = curr->next;
			free(curr);
			curr = next;
		}
		*stack = NULL;
	}
}
