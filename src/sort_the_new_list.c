/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_new_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:42 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:10:09 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	inside(t_push **sorted, t_push *current)
{
	t_push	*ptr;

	if (*sorted == NULL || current->stack_data < (*sorted)->stack_data)
	{
		current->next = *sorted;
		*sorted = current;
	}
	else
	{
		ptr = *sorted;
		while (ptr->next != NULL && ptr->next->stack_data < current->stack_data)
			ptr = ptr->next;
		current->next = ptr->next;
		ptr->next = current;
	}
}

void	insert_sort(t_push **push_to_sort)
{
	t_push	*sorted;
	t_push	*current;
	t_push	*next;

	sorted = NULL;
	current = *push_to_sort;
	while (current)
	{
		next = current->next;
		inside(&sorted, current);
		current = next;
	}
	*push_to_sort = sorted;
}

void	fill_data(t_push **push)
{
	t_push	*ptr;
	int		i;

	ptr = *push;
	i = 0;
	while (ptr)
	{
		ptr->push_data = i;
		i++;
		ptr = ptr->next;
	}
}

void	change_data(t_push **push, t_list **list)
{
	t_list	*ptr;
	t_push	*push1;

	ptr = *list;
	while (ptr)
	{
		push1 = *push;
		while (push1)
		{
			if (*(int *)ptr->content == push1->stack_data)
			{
				*(int *)ptr->content = push1->push_data;
				break ;
			}
			push1 = push1->next;
		}
		ptr = ptr->next;
	}
}

void	return_to_original(t_push **push, t_list **list)
{
	t_list	*ptr;
	t_push	*push1;

	ptr = *list;
	while (ptr)
	{
		push1 = *push;
		while (push1)
		{
			if (*(int *)ptr->content == push1->push_data)
			{
				*(int *)ptr->content = push1->stack_data;
				break ;
			}
			push1 = push1->next;
		}
		ptr = ptr->next;
	}
}
