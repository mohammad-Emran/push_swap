/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:40 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/05 11:26:31 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_list **stack_to_sort, char *op1, char *op2, char *op3)
/*
	op1 = sa/ sb
	op2 = rra/ rrb
	op3 = ra / rb
*/
{
	t_list	*stack;
	int		first_node;
	int		second_node;
	int		third_node;

	stack = *stack_to_sort;
	first_node = *(int *)stack->content;
	second_node = *(int *)stack->next->content;
	third_node = *(int *)stack->next->next->content;
	if (first_node > second_node && second_node > third_node)
	{
		swap(stack_to_sort, op1);
		rrotations(stack_to_sort, op2);
	}
	else if (first_node > third_node && third_node > second_node)
		rotations(stack_to_sort, op3);
	else if (second_node > first_node && first_node > third_node)
		rrotations(stack_to_sort, op2);
	else if (second_node > third_node && third_node > first_node)
	{
		swap(stack_to_sort, op1);
		rotations(stack_to_sort, op3);
	}
	else if (third_node > first_node && first_node > second_node)
		swap(stack_to_sort, op1);
}

int	find_pos(t_list **stack_pos, int value)
{
	t_list	*stack;
	int		pos;

	stack = *stack_pos;
	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	edit(t_list **stack_to_edit, int value)
{
	int	pos;
	int	size;

	pos = find_pos(stack_to_edit, value);
	size = ft_lstsize(*stack_to_edit);
	if (pos <= size / 2)
		while (*(int *)(*stack_to_edit)->content != value)
			rotations(stack_to_edit, "ra");
	else
		while (*(int *)(*stack_to_edit)->content != value)
			rrotations(stack_to_edit, "rra");
}

void	sort_4(t_list **stack_1, t_list **stack_2)
{
	int	smallest;

	smallest = smallest_number(stack_1);
	edit(stack_1, smallest);
	pushs(stack_2, stack_1, "pb");
	sort_3(stack_1, "sa", "rra", "ra");
	pushs(stack_1, stack_2, "pa");
}

void	sort_5(t_list **stack_1, t_list **stack_2)
{
	int	smallest;

	smallest = smallest_number(stack_1);
	edit(stack_1, smallest);
	pushs(stack_2, stack_1, "pb");
	smallest = smallest_number(stack_1);
	edit(stack_1, smallest);
	pushs(stack_2, stack_1, "pb");
	sort_3(stack_1, "sa", "rra", "ra");
	pushs(stack_1, stack_2, "pa");
	pushs(stack_1, stack_2, "pa");
}
