/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:09:31 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/01 18:10:24 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**join_args(char **argv)
{
	char	**args;
	char	*join;
	char	*tmp;
	int		i;

	if (!argv)
		return (NULL);
	i = 1;
	tmp = ft_calloc(1, 1);
	while (argv[i])
	{
		join = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = ft_strjoin(join, " ");
		free(join);
		i++;
	}
	args = ft_split(tmp, ' ');
	free(tmp);
	return (args);
}
