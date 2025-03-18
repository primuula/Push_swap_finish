/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:41:13 by safamran          #+#    #+#             */
/*   Updated: 2025/03/13 14:19:48 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_element
{
	int					value;
	int					index;
	struct t_element	*next;
}						t_element;

typedef struct t_stack
{
	int					size;
	struct t_element	*top;
}						t_stack;

// control_stack
void					print_stack(t_stack *stack_a, t_stack *stack_b);
t_stack					*create_stack(void);
t_element				*create_element(int value);
void					push_element(int value, t_stack *stack);


//main
void					sorting(t_stack *stack_a, t_stack *stack_b);
void					space_and_solo(char *str);
void					just_error();

// parsing
t_stack					*parse_it(int argc, char *argv[]);
int						incorrect_number(char *str);
int						is_doublon(t_stack *stack, int nb);
long					ft_atol(char *str);
t_stack					*parse_string(char *str);
int						count_tab(char **tab);
int						is_str_ok(char *str, t_stack *stack_a);
t_stack 				*check_and_fill(char **tab, t_stack *stack_a);
void  					free_tab(char **tab);

//error
void					free_stack(t_stack *stack_a);
void					error_and_free(t_stack *stack);
void					just_free(t_stack *stack);

// mouv
void					swap(t_stack *stack);
void					swap_a(t_stack *stack);
void					swap_b(t_stack *stack);
void					swap_ab(t_stack *stack_a, t_stack *stack_b);

void					push(t_stack *stack_from, t_stack *stack_into);
void					push_a(t_stack *stack_b, t_stack *stack_a);
void					push_b(t_stack *stack_a, t_stack *stack_b);

void					rotate(t_stack *stack);
void					rotate_a(t_stack *stack_a);
void					rotate_b(t_stack *stack_b);
void					rotate_ab(t_stack *stack_a, t_stack *stack_b);

void					rev_rotate(t_stack *stack);
void					rev_rotate_a(t_stack *stack_a);
void					rev_rotate_b(t_stack *stack_b);
void					rev_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// OUTILS
int						verif_sorted(t_stack *stack_a);
t_element				*return_min(t_stack *stack_a);
t_element				*return_max(t_stack *stack_a);
int						need_bits(t_stack *stack_a);
t_element				*return_min_after(t_stack *stack_a);
void					index_it(t_stack *stack_a);

// OUTILS CHUNK
int						get_chunk_count(int size);
int						find_closest_in_chunk(t_stack *stack, int chunk_start, int chunk_end);
void					move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end);
void					insert_back_to_a(t_stack *stack_a, t_stack *stack_b);

//split
int						countword(char *str, char c);
void					megafree(char **tab, int i);
char					*allouee(char *str, char c);
char					**my_split(char const *s, char c);

// tri
void					sort_two(t_stack *stack_a);
void					sort_three(t_stack *stack_a);
void					sort_four_five_six(t_stack *stack_a, t_stack *stack_b);
void					sort_rad(t_stack *stack_a, t_stack *stack_b);
void					sort_chunk(t_stack *stack_a, t_stack *stack_b);

#endif