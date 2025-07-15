/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:45:03 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 19:07:34 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	unsorted_bits(unsigned place, unsigned max_value)
{
	unsigned int	exponent;

	exponent = 1;
	while ((unsigned int) 2 << (exponent - 1) <= max_value)
		exponent++;
	return (place <= exponent);
}

void	rad_lsd(t_node *a, t_node *b)
{
	unsigned int	size;
	unsigned int	place;
	unsigned int	i;

	size = node_count(a);
	place = 1;
	i = 0;
	while (unsorted_bits(place, size))
	{
		while (i < size)
		{
			if (!b && already_sorted(a))
				return ;
			if ((a->index >> (place - 1) & 1) == 0)
				push(&a, &b, "pb\n");
			else
				rot(&a);
			i++;
		}
		while (b)
			push(&b, &a, "pa\n");
		i = 0;
		place++;
	}
}
