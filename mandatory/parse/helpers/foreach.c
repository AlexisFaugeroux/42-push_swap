/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:29:10 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/28 22:31:44 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	foreach(char **data, size_t	size, void (*f)(char *))
{
	return (ft_foreach((void **)data, size, (void (*)(void *))f));
}
