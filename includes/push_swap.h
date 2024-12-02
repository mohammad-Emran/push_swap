/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <malja-fa@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:26:32 by malja-fa          #+#    #+#             */
/*   Updated: 2024/12/02 11:10:15 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_push
{
	int				stack_data;
	int				push_data;
	struct s_push	*next;

}					t_push;

typedef struct s_vars
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_push			*push;
	char			**str;
}					t_vars;

long long			my_atoi(const char *str, t_list **stack_a);
long long			my_atoi2(const char *str, t_list **stack_a, char **argv);
void				check_dup(char **argv, t_list **stack_a);
void				check_dup2(char **argv, t_list **stack_a);
void				check_range(long long num, t_list **stack_a);
void				check_range2(long long num, t_list **stack_a, char **argv);
int					sorted(t_list **stack_to_check);
char				**splitt(char **argv, int argc);
void				error(t_list **stack_a);
void				error2(t_list **stack_a, char **argv);
void				check(t_list **stack_to_check, char **argv);
void				check2(t_list **stack_to_check, char **argv);
void				del(void *content);
void				ft_free_split(char **str);
void				del_stacks(t_list **stack_a, t_list **stack_b,
						t_push **push);

void				pushs(t_list **stack_to_add, t_list **stack_to_pull,
						char *str);
void				swap(t_list **array_to_rotate, char *str);
void				rotations(t_list **stack_to_rotate, char *str);
void				rrotations(t_list **stack_to_reverse, char *str);
void				mixes(t_list *stack_a, t_list *stack_b, char *str);

int					smallest_number(t_list **stack_to_search);
int					find_pos(t_list **stack_pos, int value);
void				sort_3(t_list **stack_to_sort, char *op1, char *op2,
						char *op3);
void				sort_4(t_list **stack_1, t_list **stack_2);
void				sort_5(t_list **stack_1, t_list **stack_2);

void				radix_sort(t_list **stack_a, t_list **stack_b);
int					max_bit(int value);
int					max_number(t_list **stack_1);

t_push				*push_lstnew(int stack_data, int push_data);
void				push_lstadd_back(t_push **lst, t_push *new);
void				create_a_list(t_push **push_list, t_list **stack_a);
void				change_data(t_push **push, t_list **list);
void				insert_sort(t_push **push_to_sort);
void				fill_data(t_push **push);
void				return_to_original(t_push **push, t_list **list);
int					push_lstsize(t_push *lst);
t_push				*push_lstnew(int stack_data, int push_data);
void				push_lstadd_back(t_push **lst, t_push *new);
void				radix(t_list **stack_a, t_list **stack_b, t_push **push);
void				start_sort(int argc, t_list **stack_a, t_list **stack_b,
						t_push **push);
void				init(t_list **stack_a, char **argv);
void				init2(t_list **stack_a, char **argv);
void				push_lstclear(t_push **lst);
#endif