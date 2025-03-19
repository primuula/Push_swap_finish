/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:54:04 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:12:31 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_free(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_element	*un;
	t_element	*deux;

	un = stack->top;
	while (un != NULL)
	{
		deux = un->next;
		free(un);
		un = deux;
	}
	free(stack);
}

void	just_free(t_stack *stack)
{
	if (stack)
		free_stack(stack);
}

void	just_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
