#include "push_swap.h"
#include <stdio.h>

void	interact(t_node *a, t_node *b)
{
	char	input[10];

	scanf("%s", input);
	while (input[0] != 'q')
	{
		if (input[0] == 's' && input[1] == 'a')
			swap(&a, &b);
		if (input[0] == 's' && input[1] == 'b')
			swap(&b, &a);
		if (input[0] == 'r' && input[1] == 'a')
			a = a->next;
		if (input[0] == 'r' && input[1] == 'b')
			b = b->next;
		show_stacks(a, b);
		scanf("%s", input);
	}
}

static void show_stack(t_node *stack)
{
	t_node *next_to_go;

	if (!stack)
	{
		printf("stack empty");
		return ;
	}
	printf("%i ", stack->value);
	next_to_go = stack->next;
	while (stack != next_to_go)
	{
		printf("%i ", next_to_go->value);
		next_to_go = next_to_go->next;
	}
}

void show_stacks(t_node *a, t_node *b)
{
	printf("a: ");
	show_stack(a);
	printf("\nb: ");
	show_stack(b);
	printf("\n\n");
}
