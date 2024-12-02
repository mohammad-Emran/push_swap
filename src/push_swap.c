/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:26 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:09:59 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_list **stack_a)
{
	ft_lstclear(stack_a, del);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	del(void *content)
{
	free(content);
	content = NULL;
}

void	push_lstclear(t_push **lst)
{
	t_push	*ptr;
	t_push	*temp;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}

void	start_sort(int argc, t_list **stack_a, t_list **stack_b, t_push **push)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (sorted(stack_a))
	{
		ft_lstclear(stack_a, del);
		return ;
	}
	if (argc < 2)
		error(stack_a);
	else
	{
		if (stack_size > 5)
			radix(stack_a, stack_b, push);
		else if (stack_size == 2)
			swap(stack_a, "sa");
		else if (stack_size == 3)
			sort_3(stack_a, "sa", "rra", "ra");
		else if (stack_size == 4)
			sort_4(stack_a, stack_b);
		else if (stack_size == 5)
			sort_5(stack_a, stack_b);
	}
}

void	init(t_list **stack_a, char **argv)
{
	int		i;
	t_list	*p;
	int		*x;

	i = 0;
	while (argv[i])
	{
		x = malloc(sizeof(int));
		if (!x)
			error(stack_a);
		*x = my_atoi(argv[i], stack_a);
		p = ft_lstnew(x);
		if (!p)
		{
			free(x);
			error(stack_a);
		}
		ft_lstadd_back(stack_a, p);
		i++;
	}
}
/*
void printt (t_list **stack)
{
	t_list *stat;
	stat = *stack;
	while (stat)
	{
		printf ("%d\n", *(int *)stat->content);
		stat = stat->next;
	}
} */