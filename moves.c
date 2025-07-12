/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:12:00 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/12 15:16:51 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **src, t_node **dest)
{
	t_node	*trip;

	if (!*src)  // TODO unnecessary when finished
		return ;
	trip = *src;
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
