/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:31:16 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:08:55 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y] != 0)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

int	is_str_ok(char *str, t_stack *stack_a)
{
	long	nb;

	if (incorrect_number(str) == 0 || str[0] == '\0')
		return (0);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	if (is_doublon(stack_a, (int)nb) == 0)
		return (0);
	push_element((int)nb, stack_a);
	return (1);
}

t_stack	*check_and_fill(char **tab, t_stack *stack_a)
{
	int	i;

	i = count_tab(tab) - 1;
	while (i >= 0)
	{
		if (is_str_ok(tab[i], stack_a) == 0)
		{
			free_tab(tab);
			error_and_free(stack_a);
			return (NULL);
		}
		i--;
	}
	return (stack_a);
}

t_stack	*parse_string(char *str)
{
	t_stack	*stack_a;
	char	**tab;

	stack_a = create_stack();
	tab = my_split(str, ' ');
	if (!tab)
	{
		free_stack(stack_a);
		return (NULL);
	}
	stack_a = check_and_fill(tab, stack_a);
	free_tab(tab);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}
