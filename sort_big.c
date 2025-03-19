/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:26:22 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:09:28 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rad(t_stack *stack_a, t_stack *stack_b)
{
	int	bits_col;
	int	c;
	int	i;
	int	size;

	bits_col = need_bits(stack_a) + 1;
	c = 0;
	size = stack_a->size;
	index_it(stack_a);
	while (c < bits_col)
	{
		i = 0;
		while (i < size)
		{
			if (((stack_a->top->index >> c) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			i++;
		}
		while (stack_b->size > 0)
			push_a(stack_b, stack_a);
		c++;
		if (verif_sorted(stack_a) == 1)
			break ;
	}
}
