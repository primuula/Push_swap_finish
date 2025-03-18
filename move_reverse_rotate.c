#include "push_swap.h"

void	rev_rotate(t_stack *stack)
{
	t_element	*one;
	t_element	*der;
	t_element	*avder;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	one = stack->top;
	der = stack->top;
	avder = stack->top;
	while (der->next != NULL)
	{
		der = der->next;
	}
	while (avder->next != der) // pour trouver l avant dernier maillion puis
	{
		avder = avder->next;
	}
	avder->next = NULL;
		// puis le faire pointer vers null (qu il devienne dernier)
	der->next = one;
	stack->top = der;
}

void	rev_rotate_a(t_stack *stack_a)
{
	printf("here1\n");
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	rev_rotate(stack_a);

	printf("here");

	write(1, "rra\n", 4);
}
void	rev_rotate_b(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if ((!stack_a || !stack_a->top || !stack_a->top->next) || (!stack_b
			|| !stack_b->top || !stack_b->top->next))
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}