/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:55:09 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/13 11:38:35 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argument_is_valid(char *arg);
static t_node	*create_and_append(int num, t_node *a);

t_node	*args_to_circular_doubly_linked_list(int argc, char **argv, t_node *a)
{
	int	i;
	int	number;
	int	overflow;

	i = 1;
	overflow = 0;
	while (i < argc)
	{
		if (argument_is_valid(argv[i]))
		{
			number = atoijoi(argv[i], &overflow);
			if (overflow)
			{
				free_stack(a);
				// print error
			}
			a = create_and_append(number, a);
		}
		i++;
	}
	return (a->next);
}

static int	argument_is_valid(char *arg)
{
	// check length before atoijoi to figure out over long
	return (1);
}

static t_node	*create_and_append(int num, t_node *a)
{
	t_node	*new = malloc(sizeof(t_node));
	if (!new)
	{
		free_everything(a, NULL);
		exit (1);
	}
	new->value = num;
	if (!a)
	{
		new->next = new;
		new->prev = new;
		return (new);
	}
	new->prev = a;
	new->next = a->next;
	a->next->prev = new;
	a->next = new;
	return (new);
}
