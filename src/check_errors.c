/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:07 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:09:44 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	my_atoi(const char *str, t_list **stack_a)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (*str != '\0')
		error(stack_a);
	return ((result * sign));
}

void	check_range(long long num, t_list **stack_a)
{
	if (num > INT_MAX || num < INT_MIN)
		error(stack_a);
}

void	check_dup(char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 0;
	j = 0;
	num1 = 0;
	num2 = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			num1 = my_atoi(argv[i], stack_a);
			num2 = my_atoi(argv[j], stack_a);
			if (num1 == num2)
			{
				error(stack_a);
			}
			j++;
		}
		i++;
	}
}

int	sorted(t_list **stack_to_check)
{
	t_list	*temp;
	t_list	*stack;

	if (!stack_to_check || !(*stack_to_check))
		return (1);
	stack = *stack_to_check;
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (*((int *)stack->content) > *((int *)temp->content))
				return (0);
			temp = temp->next;
		}
		(stack) = (stack)->next;
	}
	return (1);
}

void	check(t_list **stack_to_check, char **argv)
{
	int			i;
	long long	num;

	i = 0;
	check_dup(argv, stack_to_check);
	while (argv[i])
	{
		num = my_atoi(argv[i], stack_to_check);
		check_range(num, stack_to_check);
		i++;
	}
}
