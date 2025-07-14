/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:56:16 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:37:14 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 2)
		return (0);
	if (has_duplicates(argc, argv))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	a = args_to_circular_doubly_linked_list(argc, argv, a);
	normal_map(&a);
	if (already_sorted(a))
		;
	else if (argc <= 4 || argc == 6)
		small_sort(a);
	else
		rad_lsd(a, b);
	free_everything(a, b);
	return (0);
}
