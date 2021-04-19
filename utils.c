/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:50:51 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 11:39:12 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*next;

	printf("A :");
	if (stack_a != NULL)
	{
		next = stack_a->next;
		printf(" %d", stack_a->content);
		while (next)
		{
			printf(" %d", next->content);
			next = next->next;
		}
	}
	printf("\n");
	printf("B :");
	if (stack_b != NULL)
	{
		next = stack_b->next;
		printf(" %d", stack_b->content);
		while (next)
		{
			printf(" %d", next->content);
			next = next->next;
		}
	}
	printf("\n");
}

void	print_stk(t_stack *stk)
{
	t_stack		*next;

	next = stk;
	while (next)
	{
		if (next->content >= 0)
			printf("      %d [%d] --> %d\n", next->content, next->index, next->keep);
		else
			printf("     %d [%d] --> %d\n", next->content, next->index, next->keep);
		next = next->next;
	}
}

void		clear_keep(t_stack *stk)
{
	while (stk)
	{
		stk->keep = 0;
		stk = stk->next;
	}
}
