/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:02:15 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:07:26 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_into)
{
	t_element	*temp;

	if (!stack_from || !stack_into || !stack_from->top)
		return ;
	temp = stack_from->top;
	stack_from->top = stack_from->top->next;
	temp->next = stack_into->top;
	stack_into->top = temp;
	stack_from->size--;
	stack_into->size++;
}

void	push_a(t_stack *stack_b, t_stack *stack_a)
{
	if (!stack_b || !stack_a || !stack_b->top)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_a->top)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
