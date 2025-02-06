/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:46:11 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/28 21:47:53 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	matrix_error(t_matrix *matrix)
{
	ft_putstr_fd("Error\n", 2);
	free_matrix(matrix, matrix->size);
	exit(EXIT_SUCCESS);
}
