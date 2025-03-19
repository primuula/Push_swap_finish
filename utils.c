/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:08:05 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:11:00 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_sorted(t_stack *stack_a)
{
	t_element	*maillon;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (1);
	maillon = stack_a->top;
	while (maillon->next != NULL)
	{
		if (maillon->value > maillon->next->value)
			return (0);
		maillon = maillon->next;
	}
	return (1);
}

t_element	*return_min(t_stack *stack_a)
{
	t_element	*maillon;
	t_element	*min;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (NULL);
	min = stack_a->top;
	maillon = stack_a->top;
	while (maillon->next != NULL)
	{
		if (maillon->next->value < min->value)
			min = maillon->next;
		maillon = maillon->next;
	}
	return (min);
}

t_element	*return_max(t_stack *stack_a)
{
	t_element	*maillon;
	t_element	*max;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (NULL);
	max = stack_a->top;
	maillon = stack_a->top;
	while (maillon->next != NULL)
	{
		if (maillon->next->value > max->value)
			max = maillon->next;
		maillon = maillon->next;
	}
	return (max);
}
