/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:54:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:28:35 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_to_next(t_stack **prev, t_stack **curr)
{
	*prev = *curr;
	*curr = (*curr)->next;
}

static void	sort(t_stack **stack, t_stack **prev,
					t_stack **curr, t_stack **next)
{
	if (*prev)
		(*prev)->next = *next;
	else
		*stack = *next;
	(*curr)->next = (*next)->next;
	(*next)->next = *curr;
	*prev = *next;
}

void	stack_sort(t_stack **stack, int (*cmp)(int, int))
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	bool	sorted;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	sorted = false;
	while (!sorted)
	{
		sorted = true;
		prev = NULL;
		curr = *stack;
		while (curr && curr->next)
		{
			next = curr->next;
			if (cmp(curr->value, next->value) > 0)
			{
				sort(stack, &prev, &curr, &next);
				sorted = false;
			}
			else
				move_to_next(&prev, &curr);
		}
	}
}
