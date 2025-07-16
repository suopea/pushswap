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
	{
		if (argc == 2)
			exit_if_not_a_valid_number(argv[1], a);
		return (0);
	}
	a = args_to_linked_list(argc, argv, a);
	if (has_duplicates(a))
		error_free_and_exit(a);
	normal_map(&a);
	if (argc <= 6 && !already_sorted(a))
		small_sort(a, b);
	else if (!already_sorted(a))
		rad_lsd(a, b);
	free_everything(a, b);
	return (0);
}
