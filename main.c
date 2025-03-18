/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:05:45 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 15:09:51 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mimi
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = parse_string(argv[1]);
	else	
		stack_a = parse_it(argc, argv);
	if (!stack_a)
	{
		error_and_free(stack_a);
		return (0);
	}
	stack_b = create_stack();
	if (!stack_b)
	{
		error_and_free(stack_b);
		return (0);
	}
	if (verif_sorted(stack_a) == 1)
	{
		printf("%s", "Already_sorted\n");
		just_free(stack_a);
		just_free(stack_b);
		return (0);
	}
	//print_stack(stack_a, stack_b);
	if (stack_a->size <= 6)
	{
		if (stack_a->size == 2)
			sort_two(stack_a);
		if (stack_a->size == 3)
			sort_three(stack_a);
		if (stack_a->size == 4 || stack_a->size == 5 || stack_a->size == 6)
			sort_four_five_six(stack_a, stack_b);
	}
	else
		sort_chunk(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	just_free(stack_a);
	just_free(stack_b);
	return (0);
}
