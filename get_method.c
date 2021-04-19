/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:02:24 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 12:08:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_meth		get_method(t_stack *stk)
{
	t_meth		index;
	t_meth		great;

	index = get_index_head(stk);
	great = get_greater_head(stk);
	index.name = "index";
	great.name = "great";
	if (index.nbr == great.nbr)
	{
		if (index.from <= great.from)
			return (index);
		else
			return (great);
	}
	if (great.nbr > index.nbr)
		return (great);
	else
		return (index);
}

t_meth		get_greater_head(t_stack *stack)
{
	int			n;
	int			head;
	t_meth		great;

	head = 0;
	great.from = ft_stksize(stack);
	while (stack)
	{
		great.nbr = stack->index;
		n = get_n_greater(stack->next, stack->content);
		if (head < n || (head == n && great.nbr < great.from))
		{
			great.from = great.nbr;
			head = n;
		}
		stack = stack->next;
	}
	great.nbr = head;
	return (great);
}

t_meth		get_index_head(t_stack *stk)
{
	int			head;
	t_meth		index;
	int			n;

	head = 0;
	index.from = ft_stksize(stk) - 1;
	while (stk)
	{
		index.nbr = stk->index;
		n = get_n_index(stk->next, stk->index);
		if (head < n || (head == n && index.nbr < index.from))
		{
			index.from = index.nbr;
			head = n;
		}
		stk = stk->next;
	}
	index.nbr = head;
	return (index);
}
