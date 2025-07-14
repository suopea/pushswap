/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:43:46 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:36:42 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node *a);
static void	sort_five(t_node *a);

void	small_sort(t_node *a)
{
	if (node_count(a) == 2)
		write(1, "sa\n", 4);
	else if (node_count(a) == 3)
		sort_three(a);
	else
		sort_five(a);
}

static void	sort_three(t_node *a)
{
	if (a->index == 1 && a->next->index == 3 && a->prev->index == 2)
		write(1, "pb\nra\npa\n", 9);
	if (a->index == 2 && a->next->index == 3 && a->prev->index == 1)
		write(1, "ra\nra\n", 6);
	if (a->index == 2 && a->next->index == 1 && a->prev->index == 3)
		write(1, "sa\n", 3);
	if (a->index == 3 && a->next->index == 1 && a->prev->index == 2)
		write(1, "ra\n", 3);
	if (a->index == 3 && a->next->index == 2 && a->prev->index == 1)
		write(1, "ra\nsa\n", 6);
}

static void	sort_five(t_node *a)
{
}
