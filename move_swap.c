/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:28:18 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 14:51:58 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_element	*first;
	t_element	*sec;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	sec = stack->top->next;
	first->next = sec->next;
	sec->next = first;
	stack->top = sec;
}

void	swap_a(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}
void	swap_b(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}