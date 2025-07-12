/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:07:45 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/12 14:31:22 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				index;
}	t_node;

int		atoijoi(const char *num, int *oijoi);
t_node	*args_to_list(int argc, char **argv, t_node *a);
void	free_everything(t_node *a, t_node *b);
void	swap(t_node **a, t_node **b);

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648


void	show_stacks(t_node *a, t_node *b);
void	interact(t_node *a, t_node *b);

#endif
