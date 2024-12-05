/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:37:14 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/05 11:26:00 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	my_atoi2(const char *str, t_list **stack_a, char **argv)
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
	if (*str == '\0')
		error2(stack_a, argv);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (*str != '\0')
		error2(stack_a, argv);
	return ((result * sign));
}

void	check_range2(long long num, t_list **stack_a, char **argv)
{
	if (num > INT_MAX || num < INT_MIN)
		error2(stack_a, argv);
}

void	check_dup2(char **argv, t_list **stack_a)
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
			num1 = my_atoi2(argv[i], stack_a, argv);
			num2 = my_atoi2(argv[j], stack_a, argv);
			if (num1 == num2)
			{
				error2(stack_a, argv);
			}
			j++;
		}
		i++;
	}
}

void	init2(t_list **stack_a, char **argv)
{
	int		i;
	t_list	*p;
	int		*x;

	i = 0;
	while (argv[i])
	{
		x = malloc(sizeof(int));
		if (!x)
			error2(stack_a, argv);
		*x = my_atoi2(argv[i], stack_a, argv);
		p = ft_lstnew(x);
		if (!p)
		{
			free(x);
			error2(stack_a, argv);
		}
		ft_lstadd_back(stack_a, p);
		i++;
	}
}

void	check2(t_list **stack_to_check, char **argv)
{
	int			i;
	long long	num;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 10)
			error2(stack_to_check, argv);
		check_dup2(argv, stack_to_check);
		while (argv[i])
		{
			num = my_atoi2(argv[i], stack_to_check, argv);
			check_range2(num, stack_to_check, argv);
			i++;
		}
	}
}
