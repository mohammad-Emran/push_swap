/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a_new_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:12 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:09:50 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_lstsize(t_push *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_push	*push_lstnew(int stack_data, int push_data)
{
	t_push	*node;

	node = (t_push *)malloc(sizeof(t_push));
	if (node == NULL)
		return (NULL);
	node->stack_data = stack_data;
	node->push_data = push_data;
	node->next = NULL;
	return (node);
}

void	push_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
}

void	create_a_list(t_push **push_list, t_list **stack_a)
{
	t_list	*stack;
	t_push	*push;

	stack = *stack_a;
	while (stack)
	{
		push = push_lstnew(*(int *)stack->content, 0);
		if (!push)
		{
			push_lstclear(push_list);
			error(stack_a);
		}
		push_lstadd_back(push_list, push);
		stack = stack->next;
	}
}

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
