#include "push_swap.h"

int	incorrect_number(char *str)
{
	int	a;

	if (!str)
		return (0);
	a = 0;
	if ((str[a] == '-' || str[a] == '+') && str[a + 1] == '\0')
		return (0);
	while (str[a] != '\0')
	{
		if (str[a] == '+' || str[a] == '-')
			a++;
		if (str[a] < '0' || str[a] > '9')
			return (0);
		a++;
	}
	return (1);
}

int	is_doublon(t_stack *stack, int nb)
{
	t_element	*un;

	un = stack->top;
	while (un != NULL)
	{
		if (un->value == nb)
			return (0);
		un = un->next;
	}
	return (1);
}

t_stack	*parse_it(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		a;
	long	n;

	a = argc - 1;
	stack_a = create_stack();
	while (a > 0)
	{
		n = ft_atol(argv[a]);
		if (incorrect_number(argv[a]) == 0)
			error_and_free(stack_a);
		if (n < INT_MIN || n > INT_MAX)
			error_and_free(stack_a);
		if (is_doublon(stack_a, (int)n) == 0)
			error_and_free(stack_a);
		if (argv[a][0] == '\0')
			error_and_free(stack_a);
		push_element(n, stack_a);
		a--;
	}
	return (stack_a);
}

long	ft_atol(char *str)
{
	long	result;
	long	signe;
	int		a;

	a = 0;
	signe = 1;
	result = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			signe = signe * -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = result * 10 + (str[a] - '0');
		a++;
	}
	return (result * signe);
}
/*
int	main(int argc, char *argv[])
{
	if (argc <= 2)
		return(0);
	t_stack *stack_a;
	stack_a = parse_it(argc, argv);
	if (!stack_a)
	{
		write(1, "Parse_ERROR", 11);
		return(1);
	}
	write (1, "All_right\n", 10);
	free_stack(stack_a);
return (0);
}*/