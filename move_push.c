/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:02:15 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 14:52:24 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack *stack_from, t_stack *stack_into)
{
    if (!stack_from || !stack_into || !stack_from->top)
        return ;
  
    t_element *temp;

    temp = stack_from->top;

    stack_from->top = stack_from->top->next;
    temp->next = stack_into->top;
    stack_into->top = temp;

    stack_from->size--;
    stack_into->size++;
}

/*
void    push(t_stack *stack_from, t_stack *stack_into)
{
    if (!stack_from || !stack_into || !stack_from->top)
        return ;
    t_element *topfrom;
    t_element *topinto;

    topfrom = stack_from->top;
    topinto = stack_into->top;
    
    topinto = topinto->next; // element n*2 devient top
    topfrom->next = topinto; // n*1 from devient n*1 chez into

    stack_from->size--;
    stack_into->size++;
}*/
void    push_a(t_stack *stack_b, t_stack *stack_a)
{
    if (!stack_b || !stack_a || !stack_b->top)
        return ;
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}
void    push_b(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || !stack_a->top)
        return ;
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}

