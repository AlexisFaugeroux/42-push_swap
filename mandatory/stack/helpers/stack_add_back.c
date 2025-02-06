/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:25:29 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 17:07:19 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (!stack | !new)
		return ;
	if (!*stack)
		*stack = new;
	else
		stack_last(*stack)->next = new;
}
