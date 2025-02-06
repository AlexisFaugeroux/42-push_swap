/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   every.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:12:50 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/28 22:19:48 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	every(char **data, size_t size, bool (*f)(char *))
{
	return (ft_every((void **)data, size, (bool (*)(void *))f));
}
