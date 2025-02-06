/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:04:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/26 18:06:44 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*stack_at(t_stack *stack, unsigned int nb)
{
	unsigned int	i;
	t_stack			*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	i = 0;
	while (i < nb)
	{
		if (!(curr->next))
			return (NULL);
		curr = curr->next;
		i++;
	}
	return (curr);
}
