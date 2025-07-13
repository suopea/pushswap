/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:51:28 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/13 13:29:56 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoijoi(const char *nptr, int *oijoi)
{
	int		sign;
	long	out;
	int		i;

	i = 0;
	out = 0;
	sign = 1;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		out += nptr[i] - '0';
		out *= 10;
		i++;
	}
	out = out / 10 * sign;
	if (out > FT_INT_MAX || out < FT_INT_MIN)	
		*oijoi = 1;
	return (out);
}

void	free_stack(t_node *stack)
{
	t_node	*to_go;
	t_node	*next_to_go;

	next_to_go = stack->next;
	while (stack != next_to_go)
	{
		to_go = next_to_go;
		next_to_go = to_go->next;
		free(to_go);
	}
	free(stack);
	stack = NULL;
}

void	free_everything(t_node *a, t_node *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

unsigned	node_count(t_node *stack)
{
	t_node		*look;
	unsigned	i;

	look = stack->next;
	i = 1;
	while (look != stack)
	{
		look = look->next;
		i++;
	}
	return (i);
}
