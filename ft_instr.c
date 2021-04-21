/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:24 by abrun             #+#    #+#             */
/*   Updated: 2021/04/21 11:17:25 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*ft_rotate(t_stack **stk)
{
	t_stack		*tmp;
	int			n;

	n = ft_stksize(*stk);
	if (n > 1)
	{
		tmp = ft_stklast(*stk);
		ft_stkremove_last(stk);
		ft_stkadd_front(stk, tmp);
	}
	return (*stk);
}

t_stack		*ft_push(t_stack **put, t_stack **rec)
{
	t_stack		*last;

	last = ft_stklast(*put);
	if (last)
	{
		ft_stkadd_back(rec, last);
		ft_stkremove_last(put);
	}
	return (*rec);
}

t_stack		*ft_rev_rot(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*s;
	int			n;

	n = ft_stksize(*stack);
	s = *stack;
	if (n > 1)
	{
		tmp = *stack;
		s = s->next;
		tmp->next = NULL;
		ft_stkadd_back(&s, tmp);
	}
	return (s);
}
