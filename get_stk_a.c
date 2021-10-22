/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:58:08 by abrun             #+#    #+#             */
/*   Updated: 2021/10/22 14:08:36 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*get_stack_a(char **av, int ac)
{
	t_stack		*stack;
	int			i;
	t_stack		*first;

	i = 1;
	stack = ft_stknew(ft_atoi(av[i++]));
	first = stack;
	while (i < ac)
	{
		stack->keep = 0;
		stack = ft_stknew(ft_atoi(av[i++]));
		ft_stkadd_back(&first, stack);
	}
	put_index(first);
	return (first);
}

void		put_index(t_stack *stk)
{
	int			index;
	int			min;
	int			len;
	t_stack		*next;

	index = 0;
	len = ft_stksize(stk);
	min = -2147483647;
	while (len--)
	{
		next = stk;
		min = get_min(next, min);
		while (next)
		{
			if (next->content == min)
				next->index = index++;
			next = next->next;
		}
	}
}

void		put_keep(t_stack *stk, t_meth method)
{
	while (method.from != stk->index)
		stk = stk->next;
	stk->keep = 1;
	if (!ft_strncmp(method.name, "great", 5))
		stk = put_keep_great(stk);
	else
		stk = put_keep_index(stk);
}
