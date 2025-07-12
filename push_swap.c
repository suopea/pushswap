/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:56:16 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/12 15:05:41 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	a = args_to_list(argc, argv, a);
	show_stacks(a, b);
	interact(a, b);
	// index_all(a);
	// rad_lsd(a, b);
	free_everything(a, b);
	return (0);
}

