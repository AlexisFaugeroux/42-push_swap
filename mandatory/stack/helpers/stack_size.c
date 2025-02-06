/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:24:46 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 17:07:16 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*curr;

	count = 0;
	if (!stack)
		return (count);
	curr = stack;
	count = 1;
	while (curr->next)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}
