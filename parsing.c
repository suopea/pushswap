/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:55:09 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:31:33 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		exit_if_not_a_valid_number(char *arg, t_node *a);
static t_node	*create_and_append(int num, t_node *a);
static void		error_free_and_exit(t_node *stack);

t_node	*args_to_circular_doubly_linked_list(int argc, char **argv, t_node *a)
{
	int	i;
	int	number;
	int	overflow;

	i = 1;
	overflow = 0;
	while (i < argc)
	{
		exit_if_not_a_valid_number(argv[i], a);
		number = atoijoi(argv[i], &overflow);
		if (overflow)
			error_free_and_exit(a);
		a = create_and_append(number, a);
		i++;
	}
	return (a->next);
}

static void	error_free_and_exit(t_node *stack)
{
	free_stack(stack);
	write(1, "Error\n", 7);
	exit(1);
}

static void	exit_if_not_a_valid_number(char *arg, t_node *a)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (ft_strlen(arg) > 10)
		error_free_and_exit(a);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			error_free_and_exit(a);
		arg++;
	}
}

static t_node	*create_and_append(int num, t_node *a)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_everything(a, NULL);
		exit (1);
	}
	new->value = num;
	new->index = 0;
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
