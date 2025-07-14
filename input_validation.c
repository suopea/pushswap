/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:03:37 by ssuopea           #+#    #+#             */
/*   Updated: 2025/07/14 14:43:56 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2);

int	already_sorted(t_node *a)
{
	unsigned	start;
	t_node		*temp;

	start = a->index;
	temp = a->next;
	while (temp->index != start)
	{
		if (temp->index != temp->prev->index + 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (i + j < argc) // todo make sure this is correct
		{
			if (!ft_strcmp(argv[i], argv[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
