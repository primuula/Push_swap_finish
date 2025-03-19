/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:01:59 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:04:53 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	stack->top = save_one->next;
	save_one->next = NULL;
	der->next = save_one;
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
