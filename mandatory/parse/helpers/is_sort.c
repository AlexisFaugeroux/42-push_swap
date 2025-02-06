/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:22:25 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:08:51 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	is_sort(char **data, size_t	size,
				int (*cmp)(char const *, char const *))
{
	size_t	i;

	if (!data || !cmp || !size)
		return (false);
	if (size == 1)
		return (true);
	i = 1;
	while (i < size - 1)
	{
		if (cmp(data[i], data[i + 1]) > 0)
			return (false);
		i++;
	}
	return (true);
}
