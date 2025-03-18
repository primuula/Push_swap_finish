/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:00:00 by safamran          #+#    #+#             */
/*   Updated: 2025/03/18 10:30:00 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Définit le nombre de chunks selon la taille de la pile
int	get_chunk_size(int stack_size)
{
	if (stack_size <= 10)
		return (2);
	else if (stack_size <= 100)
		return (15);
	else
		return (30);
}

// Trouve l'élément avec l'index le plus petit dans stack_a
int	find_smallest_index_position(t_stack *stack_a, int max_index)
{
	t_element	*current;
	int			position;
	int			smallest_index;
	int			smallest_pos;

	current = stack_a->top;
	position = 0;
	smallest_index = max_index + 1;
	smallest_pos = -1;

	while (current)
	{
		if (current->index < smallest_index)
		{
			smallest_index = current->index;
			smallest_pos = position;
		}
		current = current->next;
		position++;
	}

	return (smallest_pos);
}

// Trouve l'élément dans le chunk courant et le place en haut de stack_a
void	move_to_top_of_stack_a(t_stack *stack_a, int target_index)
{
	t_element	*current;
	int			position;
	int			i;

	// Trouver la position de l'élément cible
	current = stack_a->top;
	position = 0;
	while (current && current->index != target_index)
	{
		current = current->next;
		position++;
	}

	// Effectuer les rotations nécessaires
	if (position <= stack_a->size / 2)
	{
		// Rotation vers le haut
		i = 0;
		while (i < position)
		{
			rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		// Rotation vers le bas
		i = 0;
		while (i < stack_a->size - position)
		{
			rev_rotate_a(stack_a);
			i++;
		}
	}
}

// Cherche l'élément avec l'index dans un chunk et le déplace en haut
void	move_chunk_elements_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end)
{
	t_element	*current;
	int			has_chunk_element;
	int			i;

	while (stack_a->size > 0)
	{
		// Vérifie si des éléments du chunk sont encore dans stack_a
		has_chunk_element = 0;
		current = stack_a->top;
		while (current)
		{
			if (current->index >= chunk_start && current->index <= chunk_end)
			{
				has_chunk_element = 1;
				break;
			}
			current = current->next;
		}

		if (!has_chunk_element)
			break;

		// Trouve l'élément le plus proche du haut/bas de la pile
		current = stack_a->top;
		i = 0;
		while (current)
		{
			if (current->index >= chunk_start && current->index <= chunk_end)
				break;
			current = current->next;
			i++;
		}

		if (i <= stack_a->size / 2)
		{
			// Rotation vers le haut
			while (!(stack_a->top->index >= chunk_start && stack_a->top->index <= chunk_end))
				rotate_a(stack_a);
		}
		else
		{
			// Rotation vers le bas
			while (!(stack_a->top->index >= chunk_start && stack_a->top->index <= chunk_end))
				rev_rotate_a(stack_a);
		}

		// Pousse l'élément dans stack_b
		push_b(stack_a, stack_b);
	}
}

// Trouve l'élément avec l'index le plus grand dans stack_b
int	find_largest_index_position(t_stack *stack_b)
{
	t_element	*current;
	int			position;
	int			largest_index;
	int			largest_pos;

	current = stack_b->top;
	position = 0;
	largest_index = -1;
	largest_pos = -1;

	while (current)
	{
		if (current->index > largest_index)
		{
			largest_index = current->index;
			largest_pos = position;
		}
		current = current->next;
		position++;
	}

	return (largest_pos);
}

// Fonction principale du chunk sort
void	sort_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	i;
	int	chunk_start;
	int	chunk_end;
	int	largest_pos;
	int	stack_size;

	if (stack_a->size <= 6)
	{
		sort_four_five_six(stack_a, stack_b);
		return ;
	}

	// Indexe d'abord la pile
	index_it(stack_a);

	// Définit la taille des chunks
	chunk_size = get_chunk_size(stack_a->size);
	stack_size = stack_a->size;

	// Traitement par chunks du plus petit au plus grand
	i = 0;
	while (i < stack_size)
	{
		chunk_start = i;
		chunk_end = i + chunk_size - 1;
		if (chunk_end >= stack_size)
			chunk_end = stack_size - 1;
		
		// Déplace les éléments du chunk courant vers stack_b
		move_chunk_elements_to_b(stack_a, stack_b, chunk_start, chunk_end);
		
		i += chunk_size;
	}

	// Remonte les éléments de stack_b vers stack_a dans l'ordre
	while (stack_b->size > 0)
	{
		// Trouve l'élément avec l'index le plus grand
		largest_pos = find_largest_index_position(stack_b);
		
		// Place l'élément en haut de stack_b
		if (largest_pos <= stack_b->size / 2)
		{
			// Rotation vers le haut
			i = 0;
			while (i < largest_pos)
			{
				rotate_b(stack_b);
				i++;
			}
		}
		else
		{
			// Rotation vers le bas
			i = 0;
			while (i < stack_b->size - largest_pos)
			{
				rev_rotate_b(stack_b);
				i++;
			}
		}
		
		// Pousse l'élément dans stack_a
		push_a(stack_b, stack_a);
	}
}