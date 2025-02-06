/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:59 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:41:51 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../mandatory/push_swap.h"

void	parse_checker(int argc, char **argv, t_matrix *matrix);

// instructions
void	sa_checker(t_stack **stack);
void	sb_checker(t_stack **stack);
void	ss_checker(t_stack **stack_a, t_stack **stack_b);
void	pa_checker(t_stack **stack_a, t_stack **stack_b);
void	pb_checker(t_stack **stack_a, t_stack **stack_b);
void	ra_checker(t_stack **stack);
void	rb_checker(t_stack **stack);
void	rr_checker(t_stack **stack_a, t_stack **stack_b);
void	rra_checker(t_stack **stack);
void	rrb_checker(t_stack **stack);
void	rrr_checker(t_stack **stack_a, t_stack **stack_b);

#endif
