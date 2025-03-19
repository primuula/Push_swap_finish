/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:20:16 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 13:42:17 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

t_element	*create_element(int value)
{
	t_element	*element;

	element = malloc(sizeof(t_element) * 1);
	if (!element)
		return (0);
	element->value = value;
	element->index = 0;
	element->next = NULL;
	return (element);
}

void	push_element(int value, t_stack *stack)
{
	t_element	*element;

	if (!stack)
		return ;
	element = malloc(sizeof(t_element));
	if (!element)
		return ;
	element->index = 0;
	element->value = value;
	element->next = stack->top;
	stack->top = element;
	stack->size++;
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_element *a;
	t_element *b;

	printf("stack A || stack B");
	printf("\n------------------\n");
	if (stack_a)
		a = stack_a->top;
	else
		a = NULL;
	if (stack_b)
		b = stack_b->top;
	else
		b = NULL;
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			printf("%d	", a->value);
			printf("{%d}", a->index);
			a = a->next;
		}
		else
			printf("       | ");
		if (b != NULL)
		{
			printf("%d", b->value);
			b = b->next;
		}
		printf("\n");
	}
}