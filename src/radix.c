/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:36 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:10:02 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_number(t_list **stack_to_search)
{
	int		small;
	t_list	*stack;

	stack = *stack_to_search;
	small = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < small)
			small = *(int *)stack->content;
		stack = stack->next;
	}
	return (small);
}

int	max_number(t_list **stack_1)
{
	t_list	*stack;
	int		value;

	stack = *stack_1;
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > value)
		{
			value = *(int *)stack->content;
		}
		stack = stack->next;
	}
	return (value);
}

int	max_bit(int value)
{
	int	max_bit;

	max_bit = 0;
	while ((value >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_bits;
	int		i;
	int		j;
	t_list	*stack;
	int		size;

	max_bits = max_bit(max_number(stack_a));
	i = 0;
	stack = *stack_a;
	size = ft_lstsize(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			stack = *stack_a;
			if (((*(int *)stack->content >> i) & 1) == 1)
				rotations(stack_a, "ra");
			else
				pushs(stack_b, stack_a, "pb");
		}
		while (ft_lstsize(*stack_b) != 0)
			pushs(stack_a, stack_b, "pa");
		i++;
	}
}

void	radix(t_list **stack_a, t_list **stack_b, t_push **push)
{
	create_a_list(push, stack_a);
	insert_sort(push);
	fill_data(push);
	change_data(push, stack_a);
	radix_sort(stack_a, stack_b);
	return_to_original(push, stack_a);
}
