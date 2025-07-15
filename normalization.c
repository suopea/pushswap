/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:42:35 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:33:50 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	normal_map(t_node **stack)
{
	int				lowest;
	unsigned int	i;
	unsigned int	size;
	t_node			*start;

	lowest = INT_MAX;
	i = 1;
	size = node_count(*stack);
	start = *stack;
	while (i < size + 1)
	{
		if (lowest == (*stack)->value
			&& !(lowest == INT_MAX && i < size))
		{
			(*stack)->index = i;
			i++;
			lowest = INT_MAX;
		}
		if (!(*stack)->index && (*stack)->value < lowest)
			lowest = (*stack)->value;
		(*stack) = (*stack)->next;
	}
	*stack = start;
}
