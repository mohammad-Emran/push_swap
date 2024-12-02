/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:19 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:09:56 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **array_to_rotate, char *str)
{
	t_list	*ptr;

	ptr = *array_to_rotate;
	if (ptr->next == NULL || !ptr || !array_to_rotate)
		return ;
	ptr = ptr->next;
	(*array_to_rotate)->next = ptr->next;
	ptr->next = *array_to_rotate;
	*array_to_rotate = ptr;
	if (str)
		ft_printf("%s\n", str);
}

void	pushs(t_list **stack_to_add, t_list **stack_to_pull, char *str)
{
	t_list	*ptr;

	if (!(*stack_to_pull))
		return ;
	ptr = *stack_to_pull;
	*stack_to_pull = ptr->next;
	ptr->next = NULL;
	ft_lstadd_front(stack_to_add, ptr);
	if (str)
		ft_printf("%s\n", str);
}

void	rotations(t_list **stack_to_rotate, char *str)
{
	t_list	*ptr;

	if (!stack_to_rotate || !(*stack_to_rotate) || !(*stack_to_rotate)->next)
		return ;
	ptr = *stack_to_rotate;
	*stack_to_rotate = ptr->next;
	ptr->next = NULL;
	ft_lstadd_back(stack_to_rotate, ptr);
	if (str)
		ft_printf("%s\n", str);
}

void	rrotations(t_list **stack_to_reverse, char *str)
{
	t_list	*ptr;
	t_list	*pre;

	if (!stack_to_reverse || !(*stack_to_reverse) || !(*stack_to_reverse)->next)
		return ;
	ptr = ft_lstlast(*stack_to_reverse);
	pre = *stack_to_reverse;
	while (pre->next != ptr)
		pre = pre->next;
	pre->next = NULL;
	ft_lstadd_front(stack_to_reverse, ptr);
	if (str)
		ft_printf("%s\n", str);
}

void	mixes(t_list *stack_a, t_list *stack_b, char *str)
{
	if (ft_strncmp(str, "ss", 2) == 0)
	{
		swap(&stack_a, NULL);
		swap(&stack_b, "ss");
	}
	else if (ft_strncmp(str, "rr", 2) == 0)
	{
		rotations(&stack_a, NULL);
		rotations(&stack_b, "rr");
	}
	else if (ft_strncmp(str, "rrr", 3) == 0)
	{
		rrotations(&stack_a, NULL);
		rrotations(&stack_b, "rrr");
	}
}
