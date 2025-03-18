#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_element	*save_one;
	t_element	*der;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	save_one = stack->top;
	der = save_one;
	while (der->next != NULL)
	{
		der = der->next;
	}
	// one est premier et der dernier pointant vers null;
	stack->top = save_one->next;
		// le second passe premier (enchainemt avec le reste)
	save_one->next = NULL;      
		// devient le "dernier" en le faisant pointer ver NULL;
	der->next = save_one;       
		// fait passer one apres le dernier; der pointe vers le nouveau last(ancien premier);
}

void	rotate_a(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if ((!stack_a || !stack_a->top || !stack_a->top->next) || (!stack_b
			|| !stack_b->top || !stack_b->top->next))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
