/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:07:45 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 18:41:04 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	unsigned int	index;
}	t_node;

t_node			*args_to_linked_list(int argc, char **argv, t_node *a);
unsigned int	node_count(t_node *stack);
int				atoijoi(const char *num, int *oijoi);
int				has_duplicates(t_node *stack);
void			normal_map(t_node **stack);
int				already_sorted(t_node *a);
void			rad_lsd(t_node *a, t_node *b);
void			push(t_node **a, t_node **b, char *move);
void			rot(t_node **a);
void			rrot(t_node **a);
void			small_sort(t_node *a, t_node *b);
void			free_stack(t_node *stack);
void			free_everything(t_node *a, t_node *b);
void			exit_if_not_a_valid_number(char *arg, t_node *a);
void			error_free_and_exit(t_node *stack);

#endif
