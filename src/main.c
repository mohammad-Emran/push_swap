/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:28:49 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:09:53 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error2(t_list **stack_a, char **argv)
{
	if (argv)
		ft_free_split(argv);
	ft_lstclear(stack_a, del);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	del_stacks(t_list **stack_a, t_list **stack_b, t_push **push)
{
	ft_lstclear(stack_a, del);
	ft_lstclear(stack_b, del);
	push_lstclear(push);
}

char	**splitt(char **argv, int argc)
{
	char	**str;

	str = ft_split(argv[argc - 1], ' ');
	if (!str)
	{
		return (NULL);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_vars	var;

	var.stack_a = NULL;
	var.stack_b = NULL;
	var.push = NULL;
	var.str = NULL;
	if (argc == 2)
	{
		var.str = splitt(argv, argc);
		if (!var.str)
			error2(&var.stack_a, var.str);
		check2(&var.stack_a, var.str);
		init2(&var.stack_a, var.str);
		ft_free_split(var.str);
	}
	else
	{
		check(&var.stack_a, argv + 1);
		init(&var.stack_a, argv + 1);
	}
	start_sort(argc, &var.stack_a, &var.stack_b, &var.push);
	del_stacks(&var.stack_a, &var.stack_b, &var.push);
	return (0);
}
