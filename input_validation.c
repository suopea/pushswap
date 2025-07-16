/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:03:37 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:38:09 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_node *a)
{
	unsigned int	start;
	t_node			*temp;

	start = a->index;
	temp = a->next;
	while (temp->index != start)
	{
		if (temp->index != temp->prev->index + 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*ahead;

	if (stack->value == stack->next->value)
		return (1);
	current = stack->next;
	while (current != stack)
	{
		ahead = current->next;
		while (ahead != current)
		{

			if (current->value == ahead->value)
				return (1);
			ahead = ahead->next;
		}
		current = current->next;
	}
	return (0);
}
