/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:48:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:34:27 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static bool	is_valid(char *action)
{
	if (ft_strcmp(action, "sa\n") == 0
		|| ft_strcmp(action, "sb\n") == 0
		|| ft_strcmp(action, "ss\n") == 0
		|| ft_strcmp(action, "pa\n") == 0
		|| ft_strcmp(action, "pb\n") == 0
		|| ft_strcmp(action, "ra\n") == 0
		|| ft_strcmp(action, "rb\n") == 0
		|| ft_strcmp(action, "rr\n") == 0
		|| ft_strcmp(action, "rra\n") == 0
		|| ft_strcmp(action, "rrb\n") == 0
		|| ft_strcmp(action, "rrr\n") == 0)
		return (true);
	return (false);
}

static void	exit_error(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("Error\n", 2);
	stack_clear(stack_a);
	stack_clear(stack_b);
	free(instruction);
	exit(EXIT_SUCCESS);
}

static void	perform(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa_checker(stack_a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb_checker(stack_b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss_checker(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa_checker(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb_checker(stack_a, stack_b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra_checker(stack_a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb_checker(stack_b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr_checker(stack_a, stack_b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra_checker(stack_a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb_checker(stack_b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr_checker(stack_a, stack_b);
	free(instruction);
}

static void	print_result(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_is_sorted(*stack_a))
	{
		ft_putstr_fd("KO\n", 2);
		stack_clear(stack_a);
		stack_clear(stack_b);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_matrix	matrix;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*instruction;

	if (argc < 2 || !argv[1][0])
		exit(EXIT_SUCCESS);
	parse_checker(argc, argv, &matrix);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, &matrix);
	instruction = get_next_line(0);
	while (instruction)
	{
		if (!is_valid(instruction))
			exit_error(instruction, &stack_a, &stack_b);
		perform(instruction, &stack_a, &stack_b);
		instruction = get_next_line(0);
	}
	free(instruction);
	print_result(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}
