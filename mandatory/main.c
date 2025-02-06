/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:06:44 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 19:34:07 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_matrix	matrix;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2 || !argv[1][0])
		exit(EXIT_SUCCESS);
	parse(argc, argv, &matrix);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, &matrix);
	if (!stack_is_sorted(stack_a))
	{
		if (stack_a->size <= 3)
			sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	stack_clear(&stack_a);
	exit(0);
}
