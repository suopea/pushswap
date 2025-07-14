/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:12:00 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:09:41 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest, char *move)
{
	t_node	*trip;

	trip = *src;
	write(1, move, 3);
	if (trip->next == trip)
		(*src) = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		(*src) = trip->next;
	}
	if (!*dest)
	{
		trip->next = trip;
		trip->prev = trip;
		(*dest) = trip;
		return ;
	}
	trip->next = (*dest);
	trip->prev = (*dest)->prev;
	(*dest)->prev = trip;
	trip->prev->next = trip;
	(*dest) = trip;
}

void rot(t_node **a)
{
	(*a) = (*a)->next;
	write(1, "ra\n", 3);
}
