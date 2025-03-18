/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:07:47 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 15:04:59 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	swap_a(stack_a);
}
void	sort_three(t_stack *stack_a)
{
	printf("here");
	int	un;
	int	deux;
	int	trois;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	un = stack_a->top->value;
	deux = stack_a->top->next->value;
	trois = stack_a->top->next->next->value;
	if (un > deux)
		swap_a(stack_a);
	if (stack_a->top->next->value > stack_a->top->next->next->value)
		rev_rotate(stack_a);
	if (stack_a->top->value > stack_a->top->next->value)
		swap_a(stack_a);
}
void	sort_four_five_six(t_stack *stack_a, t_stack *stack_b)
{
	int min;
	while (stack_a->size > 3)
	{
		min = return_min(stack_a)->value;
		if (stack_a->top->value == min)
			push_b(stack_a, stack_b);
		else
		{
			if (stack_a->top->next->value == min)
			{
				swap_a(stack_a);
				push_b(stack_a, stack_b);
			}
			else
				rotate_a(stack_a);
		}
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		push_a(stack_b, stack_a);
}
