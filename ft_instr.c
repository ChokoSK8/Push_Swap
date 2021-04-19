/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:24 by abrun             #+#    #+#             */
/*   Updated: 2021/04/16 13:13:12 by abrun            ###   ########.fr       */
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
		tmp->next =	NULL;
		ft_stkadd_back(&s, tmp);
	}
	return (s);
}

void	ft_swap(t_stack *stk)
{
	t_stack		*a;
	int			n;
	t_stack		*last;
	t_stack		*tmp;

	n = ft_stksize(stk);
	a = stk;
	while (--n > 2)
	{
		a = a->next;
	}
	last = ft_stklast(stk);
	tmp = a->next;
	a->next = last;
	last->next = tmp;
	tmp->next = NULL;
}

int		ft_sab(t_stack *stack)
{
	int		n;

	n = ft_stksize(stack);
	if (n > 1)
		ft_swap(stack);
	return (1);
}

int		ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sab(stack_a);
	ft_sab(stack_b);
	return (1);
}

int		ft_rev_rot_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rev_rot(stack_a);
	*stack_b = ft_rev_rot(stack_b);
	return (1);
}

int		ft_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rotate(stack_a);
	*stack_b = ft_rotate(stack_b);
	return (1);
}
