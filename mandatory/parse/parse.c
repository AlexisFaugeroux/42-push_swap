/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:06:28 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 19:26:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	is_digits(char *str)
{
	if (!str)
		return (false);
	if (ft_strlen(str) == 1 && (*str == '-' || *str == '+'))
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static size_t	matrix_len(char **args)
{
	size_t	len;

	if (!args)
		return (0);
	len = 0;
	while (args[len])
		len++;
	return (len);
}

static void	clean(char *str)
{
	size_t	len_src;

	if (!str || *str != '+')
		return ;
	len_src = ft_strlen(str + 1);
	ft_memmove(str, str + 1, len_src);
	str[len_src] = '\0';
}

static bool	find_dup(t_matrix *matrix)
{
	size_t	i;
	size_t	j;

	if (!matrix->data || matrix->size <= 1)
		return (false);
	i = 0;
	while (i < matrix->size)
	{
		j = i + 1;
		while (j < matrix->size)
		{
			if (ft_strcmp(matrix->data[i], matrix->data[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	parse(int argc, char **argv, t_matrix *matrix)
{
	if (argc == 2)
		matrix->data = ft_split(argv[1], ' ');
	else
		matrix->data = join_args(argv);
	if (!matrix->data)
		exit(EXIT_FAILURE);
	matrix->size = matrix_len(matrix->data);
	if (!every(matrix->data, matrix->size, is_digits) || find_dup(matrix))
		matrix_error(matrix);
	foreach(matrix->data, matrix->size, clean);
}
