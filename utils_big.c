/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:23:27 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 13:17:47 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_bits(t_stack *stack_a)
{
    int bits = 0;
    int max = stack_a->size - 1; // Indice max
    while ((1 << bits) <= max)
        bits++;
    return (bits);
}
void	index_it(t_stack *stack_a)
{
	int			index;
	int			size;
	t_element	*min_after;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	index = 0;
	size = stack_a->size;
	while (index <= size)
	{
		min_after = return_min_after(stack_a);
		min_after->index = index;
		index++;
	}
}

t_element *return_min_after(t_stack *stack_a)
{
    if (!stack_a || !stack_a->top)
        return (NULL);   
    t_element *maillon;
    t_element *min = NULL;

    
    // Trouver le premier élément non indexé
    maillon = stack_a->top;
    while (maillon)
    {
        if (maillon->index == 0)
        {
            min = maillon;
            break;
        }
        maillon = maillon->next;
    }
    
    if (!min)
        return (NULL);  // Aucun élément non indexé trouvé
    
    // Continuer à chercher le minimum parmi tous les éléments
    maillon = stack_a->top;
    while (maillon)
    {
        if ( maillon->index == 0 && maillon->value < min->value)
            min = maillon;
        maillon = maillon->next;
    }
    if (min == NULL)
        return(NULL);
    return (min);
}
