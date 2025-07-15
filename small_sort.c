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
static void	sort_four(t_node *a, t_node *b);
static void	sort_five(t_node *a, t_node *b);
static void	rot_n_push(t_node **a, t_node **b, int rots, int reverse);

void	small_sort(t_node *a, t_node *b)
{
	if (node_count(a) == 2)
		write(1, "sa\n", 4);
	else if (node_count(a) == 3)
		sort_three(a);
	else if (node_count(a) == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}

static void	sort_three(t_node *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->index;
	n2 = a->next->index;
	n3 = a->prev->index;
	if (n1 < n3 && n3 < n2)
		write(1, "pb\nra\npa\n", 9);
	else if (n3 < n1 && n1 < n2)
		write(1, "ra\nra\n", 6);
	else if (n2 < n1 && n1 < n3)
		write(1, "sa\n", 3);
	else if (n2 < n3 && n3 < n1)
		write(1, "ra\n", 3);
	else if (n3 < n2 && n2 < n1)
		write(1, "ra\nsa\n", 6);
}

static void	sort_four(t_node *a, t_node *b)
{
	unsigned int	smallest;

	smallest = 1;
	if (b)
		smallest = 2;
	if (a->index == smallest)
		push(&a, &b, "pb\n");
	else if (a->next->index == smallest)
		rot_n_push(&a, &b, 1, 0);
	else if (a->next->next->index == smallest)
		rot_n_push(&a, &b, 2, 0);
	else
		rot_n_push(&a, &b, 1, 1);
	sort_three(a);
	push(&b, &a, "pa\n");
}

static void	sort_five(t_node *a, t_node *b)
{
	if (a->index == 1)
		push(&a, &b, "pb\n");
	else if (a->next->index == 1)
		rot_n_push(&a, &b, 1, 0);
	else if (a->next->next->index == 1)
		rot_n_push(&a, &b, 2, 0);
	else if (a->prev->prev->index == 1)
		rot_n_push(&a, &b, 2, 1);
	else
		rot_n_push(&a, &b, 1, 1);
	sort_four(a, b);
	push(&b, &a, "pa\n");
}

static void	rot_n_push(t_node **a, t_node **b, int rots, int reverse)
{
	if (reverse)
	{
		rrot(a);
		if (rots == 2)
			rrot(a);
	}
	else
	{
		rot(a);
		if (rots == 2)
			rot(a);
	}
	push(a, b, "pb\n");
}
