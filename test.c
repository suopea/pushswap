#include "push_swap.h"
#include <stdio.h>

void	interact(t_node *a, t_node *b)
{
	char	input[10];
	int		show_index;

	show_index = 1;
	scanf("%s", input);
	while (input[0] != 'q')
	{
		if (input[0] == 'p' && input[1] == 'b')
			swap(&a, &b);
		if (input[0] == 'p' && input[1] == 'a')
			swap(&b, &a);
		if (input[0] == 'r' && input[1] == 'a')
			a = a->next;
		if (input[0] == 'r' && input[1] == 'b')
			b = b->next;
		if (input[0] == 'i')
			show_index *= -1;
		show_stacks(a, b, show_index);
		scanf("%s", input);
	}
}

static void show_stack(t_node *stack, int show_index)
{
	t_node *next_to_go;

	if (!stack)
	{
		printf("stack empty");
		return ;
	}
	if (show_index > 0)
		printf("%i(%i) ", stack->value, stack->index);
	else
		printf("%i ", stack->value);
	next_to_go = stack->next;
	while (stack != next_to_go)
	{
		if (show_index > 0)
			printf("%i(%i) ", next_to_go->value, next_to_go->index);
		else
			printf("%i ", next_to_go->value);
		next_to_go = next_to_go->next;
	}
}

void show_stacks(t_node *a, t_node *b, int show_index)
{
	printf("a: ");
	show_stack(a, show_index);
	printf("\nb: ");
	show_stack(b, show_index);
	printf("\n\n");
}
